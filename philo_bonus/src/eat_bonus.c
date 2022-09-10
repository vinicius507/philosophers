/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:56:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/10 17:02:30 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <unistd.h>
#include <stdio.h>

/**
 * @brief Pickups a fork from the table.
 * @philo philo The philosopher who's taking the fork
 * @return A non-zero value if the acition was succesful
 */
static int	pickup_fork(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	if ((log_action(philo, "has taken a fork") == -1))
	{
		sem_post(data->forks);
		return (1);
	}
	return (0);
}

/**
 * @brief Pickups the forks from the table.
 * @param philo The philosopher who's taking the forks
 * @return A non-zero value if the action was successful
 */
static int	pickup_forks(t_philo *philo)
{
	if ((pickup_fork(philo) != 0))
		return (1);
	if ((pickup_fork(philo) != 0))
		return (1);
	return (0);
}

/**
 * @brief Action of placing the forks back at the table.
 * @param data The simulation data
 */
static void	drop_forks(t_data *data)
{
	sem_post(data->forks);
	sem_post(data->forks);
}

/**
 * @brief Eat action of the philosopher. He will wait until
 * he has two forks to eat.
 * @param philo
 */
void	action_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if ((pickup_forks(philo) != 0))
		return ;
	philo->last_meal = log_action(philo, "is eating");
	philo->meals += 1;
	while ((get_time_since(data->start_time + philo->last_meal)
			< data->time_to_eat))
	{
		if ((check_someone_died(data) != 0))
			return (drop_forks(data));
		usleep(100);
	}
	drop_forks(data);
}
