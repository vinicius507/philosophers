/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 17:55:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 20:04:28 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <unistd.h>

static int	can_eat(t_philo *philo)
{
	if ((is_locked(philo->forks[LEFT_HAND]) != 0)
		|| (is_locked(philo->forks[RIGHT_HAND]) != 0))
		return (0);
	return (1);
}

static int	pickup_fork(t_philo *philo, int side)
{
	while ((is_locked(philo->forks[side]) != 0))
	{
		if ((check_someone_died(philo->data) != 0))
			return (1);
		if ((starved(philo) != 0))
		{
			die(philo);
			return (1);
		}
		usleep(100);
	}
	pthread_mutex_lock(&philo->forks[side]->mutex);
	set_locked(philo->forks[side]);
	log_action(philo, "has taken a fork");
	return (0);
}

static int	pickup_forks(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	if ((check_someone_died(data) != 0))
		return (1);
	pickup_fork(philo, (philo->id + 1) % 2);
	if ((check_someone_died(data) != 0))
		return (1);
	pickup_fork(philo, philo->id % 2);
	if ((check_someone_died(data) != 0))
		return (1);
	return (0);
}

static void	drop_forks(t_philo *philo)
{
	if ((is_locked(philo->forks[LEFT_HAND]) != 0))
	{
		pthread_mutex_unlock(&philo->forks[LEFT_HAND]->mutex);
		set_unlocked(philo->forks[LEFT_HAND]);
	}
	if ((is_locked(philo->forks[RIGHT_HAND]) != 0))
	{
		pthread_mutex_unlock(&philo->forks[RIGHT_HAND]->mutex);
		set_unlocked(philo->forks[RIGHT_HAND]);
	}
}

/**
 * @brief Eat action of the philosopher. He will wait until both forks from his
 * sides are available to eat.
 * @param philo
 */
void	action_eat(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	while ((can_eat(philo) == 0))
	{
		if ((check_someone_died(data) != 0))
			return ;
		if ((starved(philo) != 0))
			return (die(philo));
		usleep(100);
	}
	if ((pickup_forks(philo) != 0))
		return (drop_forks(philo));
	philo->last_meal = log_action(philo, "is eating");
	philo->meals += 1;
	while ((get_time_since(data->start_time + philo->last_meal)
			< data->time_to_eat))
	{
		if ((check_someone_died(data) != 0))
			break ;
		usleep(100);
	}
	drop_forks(philo);
}
