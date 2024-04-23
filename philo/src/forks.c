/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 00:30:39 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 19:41:32 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdlib.h>

/**
 * @brief Creates a new `fork` instance.
 * @return The allocated `fork` instance
 */
t_fork	*new_fork(void)
{
	t_fork	*fork;

	fork = malloc(1 * sizeof(t_fork));
	if (fork == NULL)
		return (NULL);
	fork->is_locked = 0;
	pthread_mutex_init(&fork->mutex, NULL);
	pthread_mutex_init(&fork->is_locked_mutex, NULL);
	return (fork);
}

/**
 * @brief Frees an array of forks
 * @param forks The array of forks
 * @return The allocated fork instance
 */
void	clear_forks(t_fork **forks)
{
	int	offset;

	if (forks == NULL)
		return ;
	offset = 0;
	while (forks[offset] != NULL)
	{
		pthread_mutex_destroy(&forks[offset]->mutex);
		pthread_mutex_destroy(&forks[offset]->is_locked_mutex);
		free(forks[offset]);
		offset++;
	}
	free(forks);
}

/**
 * @brief Creates `n` instances of a `fork`.
 * @param n The number of forks to be created
 * @return The allocated forks array
 */
t_fork	**spawn_forks(int n)
{
	int		offset;
	t_fork	**forks;

	forks = malloc((n + 1) * sizeof(t_fork *));
	if (forks == NULL)
		return (NULL);
	forks[n] = NULL;
	offset = 0;
	while (offset < n)
	{
		forks[offset] = new_fork();
		if (forks[offset] == NULL)
		{
			clear_forks(forks);
			return (NULL);
		}
		offset++;
	}
	return (forks);
}

/**
 * @brief Places forks on the round-table.
 * @param forks The forks to be placed on the table
 * @param philos The philosophers sat at the table
 * @param n The number of forks and philosophers
 */
void	place_forks(t_fork **forks, t_philo **philos, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		philos[i]->forks[LEFT_HAND] = forks[(i + 1) % n];
		philos[i]->forks[RIGHT_HAND] = forks[i];
		i++;
	}
}
