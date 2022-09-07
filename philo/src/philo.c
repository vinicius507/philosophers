/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:56:51 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 19:58:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>
#include <stdlib.h>

static void	init_data(t_data *data)
{
	data->someone_died = 0;
	data->meals = UNLIMITED_MEALS;
	pthread_mutex_init(&data->log_mutex, NULL);
	pthread_mutex_init(&data->someone_died_mutex, NULL);
}

static void	teardown_data(t_data *data)
{
	pthread_mutex_destroy(&data->log_mutex);
	pthread_mutex_destroy(&data->someone_died_mutex);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_fork	**forks;
	t_philo	**philos;

	init_data(&data);
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
	if (data.someone_died != 0)
		return (EXIT_FAILURE);
	teardown_data(&data);
	return (EXIT_SUCCESS);
}
