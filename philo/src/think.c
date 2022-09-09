/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 14:18:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/09 14:40:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>

static int	is_thinking(t_philo *philo, long int start)
{
	t_data		*data;
	long int	time;

	data = philo->data;
	time = (data->time_to_die - data->time_to_eat - data->time_to_sleep) / 2;
	if (get_time_since(start) < time)
		return (1);
	return (0);
}

/**
 * @brief Think action of the philosopher.
 * @param philo
 */
void	action_think(t_philo *philo)
{
	long int	ms;
	t_data		*data;

	data = philo->data;
	ms = log_action(philo, "is thinking");
	while ((is_thinking(philo, ms + data->start_time) != 0))
	{
		if ((check_someone_died(data) != 0))
			return ;
		if ((starved(philo) != 0))
			return (die(philo));
		usleep(100);
	}
}
