/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:39 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/10 15:54:25 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdio.h>

/**
 * @brief Checks if someone died already.
 * @param philo
 */
int	check_someone_died(t_data *data)
{
	char	someone_died;

	pthread_mutex_lock(&data->someone_died_mutex);
	someone_died = data->someone_died;
	pthread_mutex_unlock(&data->someone_died_mutex);
	return (someone_died);
}

/**
 * @brief Death action of the philosopher.
 * @param philo
 */
void	die(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&data->log_mutex);
	pthread_mutex_lock(&data->someone_died_mutex);
	if (data->someone_died == 0)
	{
		printf("%05ld %d died\n", get_time_since(data->start_time), philo->id);
		data->someone_died = 1;
	}
	pthread_mutex_unlock(&data->someone_died_mutex);
	pthread_mutex_unlock(&data->log_mutex);
}
