/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:20:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 18:14:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

static void	*philosophize(void *arg)
{
	t_data	*data;
	t_philo	*philo;

	philo = (t_philo *)arg;
	data = philo->data;
	while ((check_someone_died(data) == 0))
	{
		action_eat(philo);
		if (philo->meals == data->meals)
			break ;
		action_sleep(philo);
		action_think(philo);
	}
	return (arg);
}

/**
 * @brief Executes a philosophers simulation.
 * @param data The data of the simulation. See `t_data`
 * @param philos The philosophers of the simulation. See `t_philo`
 */
void	simulation(t_data *data, t_philo **philos)
{
	int		n;

	n = 0;
	data->start_time = get_time_in_ms();
	while (n < data->n)
	{
		philos[n]->data = data;
		pthread_create(&(philos[n]->thread_id), NULL, philosophize, philos[n]);
		n++;
	}
	n = 0;
	while (n < data->n)
	{
		pthread_join(philos[n]->thread_id, NULL);
		n++;
	}
}
