/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 14:33:47 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/09 14:35:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <unistd.h>

/**
 * @brief Sleep action of the philosopher.
 * @param philo
 */
void	action_sleep(t_philo *philo)
{
	long	ms;
	t_data	*data;

	data = philo->data;
	ms = log_action(philo, "is sleeping");
	while ((get_time_since(ms + data->start_time) < data->time_to_sleep))
	{
		if ((check_someone_died(data) != 0))
			return ;
		if ((starved(philo) != 0))
			return (die(philo));
		usleep(100);
	}
}
