/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_action.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:44:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 17:58:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>

/**
 * @brief Logs an action to STDOUT.
 * @param philo The philosopher that took the action
 * @param action_msg The message of the action to be printed
 * @return The time of the action
 */
long int	log_action(t_philo *philo, const char *action_msg)
{
	long int	ms;
	t_data		*data;

	data = philo->data;
	ms = -1;
	pthread_mutex_lock(&data->log_mutex);
	if ((check_someone_died(data) == 0))
	{
		ms = get_time_since(data->start_time);
		printf("%05ld %d %s\n", ms, philo->id, action_msg);
	}
	pthread_mutex_unlock(&data->log_mutex);
	return (ms);
}
