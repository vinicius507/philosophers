/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:04:43 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/10 19:26:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdio.h>

/**
 * @brief Gets the number of forks available.
 * @param data The simulation data. See `t_data`
 * @return The number of forks on the table
 */
int	available_forks(t_data *data)
{
	int	value;

	sem_wait(data->forks_lock);
	value = get_sem_value(data->forks);
	sem_post(data->forks_lock);
	return (value);
}
