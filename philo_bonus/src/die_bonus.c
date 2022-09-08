/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:41:39 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 18:25:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdio.h>

/**
 * @brief Checks if someone died already.
 * @param philo
 */
int	check_someone_died(t_data *data)
{
	int	someone_died;

	sem_wait(data->someone_died_lock);
	someone_died = *(int *)(data->someone_died);
	sem_post(data->someone_died_lock);
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
	sem_wait(data->someone_died_lock);
	printf("%05ld %d died\n", get_time_since(data->start_time), philo->id);
	sem_post(data->someone_died);
	sem_post(data->someone_died_lock);
}
