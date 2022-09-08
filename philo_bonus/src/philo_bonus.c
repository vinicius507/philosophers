/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 23:11:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 18:17:13 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Initializes the program data
 * @param data The simulation data
 */
static void	init_data(t_data *data)
{
	memset(data, 0, sizeof(t_data));
	data->someone_died = new_semaphore(SOMEONE_DIED, 0);
	if (data->someone_died == NULL)
		exit(EXIT_FAILURE);
	data->someone_died_lock = new_semaphore(SOMEONE_DIED_LOCK, 1);
	if (data->someone_died_lock == NULL)
		exit(EXIT_FAILURE);
}

/**
 * @brief Teardowns the simulation data
 * @param data The simulation data
 */
static void	teardown_data(t_data *data)
{
	sem_close(data->someone_died);
	sem_close(data->someone_died_lock);
	sem_unlink(SOMEONE_DIED);
	sem_unlink(SOMEONE_DIED_LOCK);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo	**philos;

	init_data(&data);
	argparse(argc, argv, &data);
	philos = spawn_philosophers(data.n);
	if (philos == NULL)
		error("could not allocated resources for the philosophers");
	else
		simulation(philos, &data);
	clear_philosophers(philos);
	teardown_data(&data);
	return (0);
}
