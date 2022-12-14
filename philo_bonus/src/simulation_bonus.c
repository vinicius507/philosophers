/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:25:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/10 19:55:12 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
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
		action_eat(philo);
		if (philo->meals == data->meals)
			break ;
		action_sleep(philo);
		action_think(philo);
		usleep(100);
	}
	clear_semaphore(data->forks, SEM_FORKS);
	clear_semaphore(data->forks_lock, SEM_FORKS_LOCK);
	clear_semaphore(data->log_lock, SEM_LOG_LOCK);
	clear_semaphore(data->someone_died, SEM_SOMEONE_DIED);
	clear_semaphore(data->someone_died_lock, SEM_SOMEONE_DIED_LOCK);
	free(philo);
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
	int	wstatus;

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
		{
			free(pids);
			philosophize(philos[i], data);
		}
		i++;
	}
	wait_all(data->n, pids);
	free(pids);
}
