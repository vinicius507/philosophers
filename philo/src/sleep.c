/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:14:13 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 20:00:08 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <unistd.h>

/**
 * @brief Sleep action of the philosopher.
 * @param philo
 */
void	action_sleep(t_philo *philo)
{
	t_data		*data;
	long int	time;

	data = philo->data;
	time = log_action(philo, "is sleeping");
	while ((get_time_since(time + data->start_time) < data->time_to_sleep))
	{
		if ((check_someone_died(data) != 0))
			return ;
		if ((starved(philo) != 0))
			return (die(philo));
		usleep(100);
	}
}
