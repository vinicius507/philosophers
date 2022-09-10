/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 18:05:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/10 16:13:24 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdlib.h>
#include <sys/time.h>
#include <bits/types/struct_timeval.h>

/**
 * @brief Gets the current system time since the Epoch in milliseconds.
 * @return The current system time in milliseconds
 */
long	get_time_in_ms(void)
{
	struct timeval	tp;
	long			ms;

	if ((gettimeofday(&tp, NULL) != 0))
		return (-1);
	ms = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (ms);
}

/**
 * @brief Gets the elapsed time from `start` in milliseconds.
 * @param start
 * @return The elapsed time from `start` in milliseconds
 */
long	get_time_since(long start)
{
	long	ms_now;

	ms_now = get_time_in_ms();
	return (ms_now - start);
}
