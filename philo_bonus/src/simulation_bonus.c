/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:25:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 16:58:59 by vgoncalv         ###   ########.fr       */
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
 * @param id The id of the philosopher
 * @param data The data of the simulation. See `t_data`
 */
static void	philosophize(int id, t_data *data)
{
	printf("philo_id: %d\n", id);
	(void)data;
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

	offset = 0;
	while (offset < n)
	{
		waitpid(pids[offset], NULL, 0);
		offset++;
	}
}

/**
 * @brief Executes a philosopher simulation with `data`.
 * @param data The data of the simulation. See `t_data`
 */
void	simulation(t_data *data)
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
			philosophize(i + 1, data);
		i++;
	}
	wait_all(data->n, pids);
	free(pids);
}
