/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:01:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 17:05:34 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <philo_bonus.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new `philosopher` instance.
 * @param id The id of the philosopher
 * @return The allocated `philosopher` instance
 */
t_philo	*new_philosopher(int id)
{
	t_philo	*philosopher;

	philosopher = malloc(1 * sizeof(t_philo));
	if (philosopher == NULL)
		return (NULL);
	memset(philosopher, 0, sizeof(t_philo));
	philosopher->id = id;
	return (philosopher);
}

/**
 * @brief Frees an array of philosophers
 * @param philosophers The array of philosophers
 * @return The allocated philosopher instance
 */
void	clear_philosophers(t_philo **philosophers)
{
	int	offset;

	if (philosophers == NULL)
		return ;
	offset = 0;
	while (philosophers[offset] != NULL)
	{
		free(philosophers[offset]);
		offset++;
	}
	free(philosophers);
}

/**
 * @brief Creates `n` instances of a `philosopher`.
 * @param n The number of philosophers to be created
 * @return The allocated philosophers array
 */
t_philo	**spawn_philosophers(int n)
{
	int		i;
	t_philo	**philosophers;

	philosophers = malloc((n + 1) * sizeof(t_philo *));
	if (philosophers == NULL)
		return (NULL);
	philosophers[n] = NULL;
	i = 0;
	while (i < n)
	{
		philosophers[i] = new_philosopher(i + 1);
		if (philosophers[i] == NULL)
		{
			clear_philosophers(philosophers);
			return (NULL);
		}
		i++;
	}
	return (philosophers);
}
