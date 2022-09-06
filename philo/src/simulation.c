/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:20:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/06 13:15:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>

static void	*philosophize(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("philo: %p\n", philo);
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
