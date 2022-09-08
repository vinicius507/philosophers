/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sem_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:48:31 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 18:24:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <fcntl.h>
#include <stdio.h>

/**
 * @brief Creates a new semaphore.
 * @param name The name of the semaphore
 * @param value The initial value of the semaphore
 */
sem_t	*new_semaphore(const char *name, int value)
{
	sem_t	*sem;

	sem_unlink(name);
	sem = sem_open(name, O_CREAT, 0664, value);
	if (sem == SEM_FAILED)
	{
		error("could not create semaphore");
		return (NULL);
	}
	return (sem);
}
