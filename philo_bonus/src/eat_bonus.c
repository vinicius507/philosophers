/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:56:25 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/09 14:32:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <unistd.h>
#include <stdio.h>

/**
 * @brief Checks if the philosopher can eat.
 * @param data The simulation data
 * @return A non-zero value if he is able to eat
 */
static int	can_eat(t_data *data)
{
	int	unused_forks;

	unused_forks = get_sem_value(data->forks);
	if (unused_forks >= 2)
		return (1);
	return (0);
}

/**
 * @brief Pickups the forks from the table.
 * @param philo The philosopher who's taking the forks
 * @return A non-zero value if the action was successful
 */
static int	pickup_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	sem_wait(data->forks);
	log_action(philo, "has taken a fork");
	while ((get_sem_value(data->forks) < 1))
	{
		if ((check_someone_died(data) != 0))
			return (1);
		if ((starved(philo) != 0))
		{
			die(philo);
			return (1);
		}
		usleep(100);
	}
	sem_wait(data->forks);
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
	while ((can_eat(data) == 0))
	{
		if ((check_someone_died(data) != 0))
			return ;
		if ((starved(philo) != 0))
			return (die(philo));
		usleep(100);
	}
	if ((pickup_forks(philo) != 0))
		return ;
	philo->last_meal = log_action(philo, "is eating");
	philo->meals += 1;
	while ((get_time_since(data->start_time + philo->last_meal)
			< data->time_to_eat))
	{
		if ((check_someone_died(data) != 0))
			return ;
		usleep(100);
	}
	drop_forks(data);
}
