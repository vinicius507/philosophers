/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 23:06:40 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/07 19:51:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# define UNLIMITED_MEALS -1

typedef pthread_mutex_t	t_mutex;

typedef struct s_data
{
	int			n;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			meals;
	long int	start_time;
	int			someone_died;
	t_mutex		log_mutex;
	t_mutex		someone_died_mutex;
}	t_data;

typedef struct s_fork
{
	int		is_locked;
	t_mutex	mutex;
	t_mutex	is_locked_mutex;
}	t_fork;

enum	e_hands
{
	LEFT_HAND,
	RIGHT_HAND,
	HANDS
};

typedef struct s_phil
{
	int			id;
	int			meals;
	pthread_t	thread_id;
	t_fork		*forks[HANDS];
	t_data		*data;
	long int	last_meal;
}	t_philo;

typedef int (t_action)(t_philo *);

int			ft_streq(const char *s1, const char *s2);

int			error(const char *err_msg);

void		argparse(int argc, char **argv, t_data *args);

void		clear_forks(t_fork **forks);

t_fork		**spawn_forks(int n);

void		clear_philosophers(t_philo **philosophers);

t_philo		**spawn_philosophers(int n);

void		place_forks(t_fork **forks, t_philo **philos, int n);

long int	get_time_in_ms(void);

long int	get_time_since(long int start);

int			is_locked(t_fork *fork);

void		set_locked(t_fork *fork);

void		set_unlocked(t_fork *fork);

int			starved(t_philo *philo);

long int	log_action(t_philo *philo, const char *action_msg);

int			check_someone_died(t_data *data);

void		die(t_philo *philo);

void		action_eat(t_philo *philo);

void		action_sleep(t_philo *philo);

void		action_think(t_philo *philo);

void		simulation(t_data *data, t_philo **philos);

#endif
