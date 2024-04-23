/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:32:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 23:34:40 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stddef.h>

/**
 * @brief Checks if two strings are equal.
 * @param s1
 * @param s2
 * @return A non-zero value if they are equal
 */
int	ft_streq(const char *s1, const char *s2)
{
	size_t	offset;

	offset = 0;
	while (s1[offset] != '\0' && s2[offset] != '\0')
	{
		if (s1[offset] != s2[offset])
			return (0);
		offset++;
	}
	return (s1[offset] == '\0' && s2[offset] == '\0');
}
