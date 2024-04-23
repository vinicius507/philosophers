/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:24:53 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 18:24:23 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int	has_help_flag(int argc, char **argv)
{
	int	offset;

	offset = 0;
	while (offset < argc)
	{
		if ((ft_streq("--help", argv[offset]) != 0))
			return (1);
		offset++;
	}
	return (0);
}

static void	usage(const char *philo)
{
	dprintf(STDERR_FILENO,
		"Usage: %s N TIME_TO_DIE TIME_TO_EAT TIME_TO_SLEEP [MEALS]\n"
		"Simulates a Dining Philosophers problem using pthreads.\n"
		"An École 42 project.\n\n"
		"Positional Arguments\n"
		"\tN\n"
		"\t\tThe number of philosophers and forks\n"
		"\tTIME_TO_DIE\n"
		"\t\tThe time (in ms) it takes for a philosopher to die\n"
		"\t\tfrom starvation.\n"
		"\tTIME_TO_EAT\n"
		"\t\tThe time (in ms) it takes for a philosopher to eat.\n"
		"\tTIME_TO_SLEEP\n"
		"\t\tThe time (in ms) it takes for a philosopher to sleep.\n"
		"\tMEALS [Optional]\n"
		"\t\tThe number of meals each philosopher has to eat.\n"
		"\t\tIf unset, the simulation stops when a philosopher dies.\n\n"
		"Flags\n"
		"\t--help\n"
		"\t\tDisplays this help message and exits.\n",
		philo);
}

static int	parse_int_arg(const char *nptr)
{
	int		digit;
	int		value;
	size_t	offset;

	value = 0;
	offset = 0;
	while (nptr[offset] != '\0')
	{
		if (offset > 9)
			return (-2);
		digit = nptr[offset] - '0';
		if (digit < 0 || digit > 9)
			return (-2);
		value *= 10;
		if (value + digit < value)
			return (-2);
		value += digit;
		offset++;
	}
	return (value);
}

static int	check_errors(t_data *data)
{
	if (data->n <= 0)
		return (error("N should be an integer greater than zero."));
	if (data->time_to_die <= 0)
		return (error("TIME_TO_DIE should be an integer greater than zero."));
	if (data->time_to_eat <= 0)
		return (error("TIME_TO_EAT should be an integer greater than zero."));
	if (data->time_to_sleep <= 0)
		return (error("TIME_TO_SLEEP should be an integer greater than zero."));
	if (data->meals != UNLIMITED_MEALS && data->meals <= 0)
		return (error("MEALS should be an integer greater than zero."));
	return (0);
}

/**
 * @brief Parses the arguments for the philosophers simulation
 * @see usage
 * @param argc
 * @param argv
 * @param data The structure which will hold the data
 */
void	argparse(int argc, char **argv, t_data *data)
{
	if ((has_help_flag(argc, argv) != 0))
	{
		usage(argv[0]);
		exit(EXIT_SUCCESS);
	}
	if (argc < 5 || argc > 6)
	{
		error("wrong number of arguments.");
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}
	data->n = parse_int_arg(argv[1]);
	data->time_to_die = parse_int_arg(argv[2]);
	data->time_to_eat = parse_int_arg(argv[3]);
	data->time_to_sleep = parse_int_arg(argv[4]);
	if (argc == 6)
		data->meals = parse_int_arg(argv[5]);
	if ((check_errors(data) != 0))
	{
		usage(argv[0]);
		exit(EXIT_FAILURE);
	}
}
