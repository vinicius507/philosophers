/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:56:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/06 13:12:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_data	data;
	t_fork	**forks;
	t_philo	**philos;

	argparse(argc, argv, &data);
	forks = spawn_forks(data.n);
	philos = spawn_philosophers(data.n);
	if (forks != NULL && philos != NULL)
	{ 
		place_forks(forks, philos, data.n);
		simulation(&data, philos);
	}
	clear_forks(forks);
	clear_philosophers(philos);
	return (0);
}
