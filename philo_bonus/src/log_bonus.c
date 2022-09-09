/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:51:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/09 13:55:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdio.h>

/**
 * @brief Logs an action of the philosopher.
 * @param philo The philosopher that executed the action
 * @param action_msg The message of the action
 * @return The interval, in ms, in which the action took place
 */
long	log_action(t_philo *philo, const char *action_msg)
{
	long	ms;
	t_data	*data;

	data = philo->data;
	sem_wait(data->log_lock);
	ms = get_time_since(data->start_time);
	if ((check_someone_died(data) == 0))
		printf("%05ld %d %s\n", ms, philo->id, action_msg);
	sem_post(data->log_lock);
	return (ms);
}
