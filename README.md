# Philosophers

This is project is about the usage of threads and mutexes.

## Description

There are `n` philosophers in a round table, each philosopher can take one of
three actions:

- Eat
- Sleep
- Think

There are `n` forks on the table, although a philosopher needs two forks to
eat, one from each side. After eating they go to sleep.

As soon as they wake up they start thinking, until they get hungry again.

## Dependencies

- GNU Make
- gcc 12

## Compilation

Clone the repository:

```sh
$ git clone https://github.com/vinicius507/philosophers.git
```

Then build the project using GNU Make:

```sh
$ make
```

## Usage

```sh
$ ./philo --help
Usage: ./philo N TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP [MEALS]
Runs a philosophers simulation using multiple threads.
An École 42 project.

ARGS
	N
		The number of philosophers and forks.
	TIME_TO_DIE
		The time, in milliseconds, it takes for a philosopher to die from.
		starvation
	TIME_TO_EAT
		The time, in milliseconds, it takes for a philosopher to eat.
	TIME_TO_SLEEP
		The time, in milliseconds, a philosopher will spend sleeping.
	MEALS [Optional]
		The number of meals each philosopher has to eat.

FLAGS
	--help
		Display this help message and exits.
```
