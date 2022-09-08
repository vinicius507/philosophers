/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:38:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 15:39:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdio.h>
#include <unistd.h>

/**
 * @brief Prints an error message to STDERR.
 * @param err_msg
 * @return A non-zero value, always
 */
int	error(const char *err_msg)
{
	return (dprintf(STDERR_FILENO, "Error: %s\n", err_msg));
}
