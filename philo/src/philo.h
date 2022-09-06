/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:06:40 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/06 13:14:56 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define UNLIMITED_MEALS -1

typedef struct s_data
{
	int			n;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals;
	long int	start_time;
}	t_data;

typedef pthread_mutex_t	t_fork;

enum	e_hands
{
	LEFT_HAND,
	RIGHT_HAND,
	HANDS
};

typedef struct s_phil
{
	pthread_t	thread_id;
	t_fork		*forks[HANDS];
	t_data		*data;
}	t_philo;

int		ft_streq(const char *s1, const char *s2);

void	argparse(int argc, char **argv, t_data *args);

void	clear_forks(t_fork **forks);

t_fork	**spawn_forks(int n);

void	clear_philosophers(t_philo **philosophers);

t_philo	**spawn_philosophers(int n);

void	place_forks(t_fork **forks, t_philo **philos, int n);

void	simulation(t_data *data, t_philo **philos);

#endif
