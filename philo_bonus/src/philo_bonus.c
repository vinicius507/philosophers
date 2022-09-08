/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:11:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 16:25:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <string.h>

/**
 * @brief Initializes the program data
 */
static void	init_data(t_data *data)
{
	memset(data, 0, sizeof(t_data));
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	argparse(argc, argv, &data);
	simulation(&data);
	return (0);
}
