/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:25:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 18:30:54 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * @brief Routine for the philosopher `id`.
 * @param philo The philosopher
 */
static void	philosophize(t_philo *philo, t_data *data)
{
	philo->data = data;
	if (philo->id % 2 == 0)
		usleep(500);
	while ((check_someone_died(data) == 0))
	{
		if ((starved(philo) != 0))
			return (die(philo));
		usleep(100);
	}
	exit(EXIT_SUCCESS);
}

/**
 * @brief Waits all philosophers processes to finish.
 * @param n The number of pids
 * @param pids The pids of the processes
 */
void	wait_all(int n, pid_t *pids)
{
	int	offset;
	int wstatus;

	offset = 0;
	while (offset < n)
	{
		waitpid(pids[offset], &wstatus, 0);
		offset++;
	}
}

/**
 * @brief Executes a philosopher simulation with `data`.
 * @param philos The philosophers of the simulation
 * @param data The data of the simulation. See `t_data`
 */
void	simulation(t_philo **philos, t_data *data)
{
	int		i;
	pid_t	*pids;

	pids = malloc(data->n * sizeof(pid_t));
	if (pids == NULL)
		error("could not allocated resources for the simulation");
	memset(pids, 0, data->n * sizeof(pid_t));
	i = 0;
	data->start_time = get_time_in_ms();
	while (i < data->n)
	{
		pids[i] = fork();
		if (pids[i] == -1)
			error("could not fork the parent process");
		if (pids[i] == 0)
			philosophize(philos[i], data);
		i++;
	}
	wait_all(data->n, pids);
	free(pids);
}
