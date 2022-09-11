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

First, clone the repository:

```sh
$ git clone https://github.com/vinicius507/philosophers.git
```

There are two formats of the project in the repository: the mandatory one and
the bonus. The mandatory part uses POSIX threads and mutexes, while the bonus
part uses process forks and POSIX semaphores.

The build the desired binary:

```sh
$ make # For the mandatory part
$ make bonus # For the bonus part
```

The mandatory binary is located inside the `philo` folder, while the bonus one
is inside the `philo_bonus` folder.

## Usage

Both mandatory and bonus binaries accept the same positional arguments:

```sh
$ ./philo --help
Usage: ./philo N TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP [MEALS]
Simulates a Dining Philosophers problem using pthreads.
An École 42 project.

Positional Arguments
	N
		The number of philosophers and forks
	TIME_TO_DIE
		The time (in ms) it takes for a philosopher to die
		from starvation.
	TIME_TO_EAT
		The time (in ms) it takes for a philosopher to eat.
	TIME_TO_SLEEP
		The time (in ms) it takes for a philosopher to sleep.
	MEALS [Optional]
		The number of meals each philosopher has to eat.
		If unset, the simulation stops when a philosopher dies.

Flags
	--help
		Displays this help message and exits.
```
