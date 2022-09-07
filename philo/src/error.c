/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 18:15:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 18:17:33 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
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
