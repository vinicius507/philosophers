/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:35:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 19:44:29 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/**
 * @brief Checks if a `fork` is being used(locked).
 * @param fork
 * @return A non-zero value if it is being used
 */
int	is_locked(t_fork *fork)
{
	int	is_locked;

	pthread_mutex_lock(&fork->is_locked_mutex);
	is_locked = fork->is_locked;
	pthread_mutex_unlock(&fork->is_locked_mutex);
	return (is_locked);
}

/**
 * @brief Locks a `fork`.
 * @param fork
 */
void	set_locked(t_fork *fork)
{
	pthread_mutex_lock(&fork->is_locked_mutex);
	fork->is_locked = 1;
	pthread_mutex_unlock(&fork->is_locked_mutex);
}

/**
 * @brief Unlocks a `fork`.
 * @param fork
 */
void	set_unlocked(t_fork *fork)
{
	pthread_mutex_lock(&fork->is_locked_mutex);
	fork->is_locked = 0;
	pthread_mutex_unlock(&fork->is_locked_mutex);
}
