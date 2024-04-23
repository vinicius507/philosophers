/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starved.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:39:32 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 14:45:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if a philosopher `philo` has starved.
 * @param philo
 * @return A non-zero value if he has starved
 */
int	starved(t_philo *philo)
{
	t_data		*data;
	long int	interval;

	data = philo->data;
	interval = get_time_since(data->start_time + philo->last_meal);
	if ((interval >= data->time_to_die))
		return (1);
	return (0);
}
