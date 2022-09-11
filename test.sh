#!/bin/bash

MAKEDIR="./philo"
BIN="./philo/philo"
NUM_TESTS=3
MAX_MEALS=4
LOG_FOLDER="./test_logs"
FAILURES=0

check_result() {
	STATUS="OK"
	CASE=$1
	SHOULD_DIE=$2
	OUTPUT_FILE=$3

	GREPED_OUT="$(grep --color=always 'died' $OUTPUT_FILE)"
	if [[ $SHOULD_DIE == true ]]; then
		if [[ -z $GREPED_OUT ]]; then
			 STATUS="KO"
			 FAILURES="$(expr $FAILURES + 1)"
		 fi
	else
		 if [[ -n $GREPED_OUT ]]; then
			 STATUS="KO"
			 FAILURES="$(expr $FAILURES + 1)"
		 fi
	fi
	[[ -n $GREPED_OUT ]] && echo "    $GREPED_OUT"
	echo "  STATUS: $STATUS"
}

run_test() {
	IT=$1
	CASE=$2
	SHOULD_DIE=$3
	OUTPUT_FILE="$LOG_FOLDER/result_$(date +'%s').out"

	echo "  \$ $BIN $CASE"
	$BIN $CASE >>"$OUTPUT_FILE" 2>/dev/null
	check_result "$CASE" $SHOULD_DIE $OUTPUT_FILE
}

run_multiple_tests() {
	CASE=$1
	SHOULD_DIE=$2
	PIDS=()

	echo "> Testing case $CASE"
	for i in $(seq $NUM_TESTS); do
		run_test "$i" "$CASE" $SHOULD_DIE
		sleep 1
	done
}

run_tests_should_live() {
	CASE="$1 $MAX_MEALS"

	run_multiple_tests "$CASE" false
}

run_tests_should_die() {
	CASE=$1

	run_multiple_tests "$CASE" true
}

check_failures_and_exit() {
	if [[ $FAILURES -gt 0 ]]; then
		echo "Error while running the tests. There were $FAILURES failures."
	fi
	exit $FAILURES
}

run_make() {
	COMMAND=$1

	make $COMMAND -C $MAKEDIR 2>&1 >/dev/null
	if [[ $? -ne 0 ]]; then
		echo "Error running make"
		exit 1
	fi
}

setup_tests() {
	mkdir -p $LOG_FOLDER; clear
	echo "> Compiling"
	run_make re
	echo "> Done"
}

teardown_tests() {
	echo "> Cleaning up"
	run_make fclean
	echo "> Done"
	check_failures_and_exit
}

test_suite() {
	setup_tests

	run_tests_should_die "3 310 200 100"

	run_tests_should_live "4 310 150 150"
	run_tests_should_live "5 600 150 150"

	teardown_tests
}

usage() {
	cat << EOF
Usage: ./test.sh [OPTIONS]...

OPTIONS
	-m	--make-dir
	  The directory containing the Makefile.
	-b	--bin-path
	  The path to the binary executable of the simulation.
	-n	--num-tests
	  The number of tests to be executed for each case.
	-M	--max-meals
	  The maximum number of meals in cases where there should be no deaths.
	-h	--help
	  Displays this help message and exits.
EOF
}

argparse() {
	while [[ $# -gt 0 ]]; do
		case $1 in
			"-m" | "--make-dir")
				MAKEDIR=$2
				shift
				shift
				;;
			"-b" | "--bin-path")
				BIN=$2
				shift
				shift
				;;
			"-n" | "--num-tests")
				NUM_TESTS=$2
				shift
				shift
				;;
			"-M" | "--max-meals")
				MAX_MEALS=$2
				shift
				shift
				;;
			"-h" | "--help")
				usage
				exit 0
				;;
			*)
				echo "Error: unknown argument $1"
				usage
				exit 1
				;;

		esac
	done
}

argparse $@
test_suite
