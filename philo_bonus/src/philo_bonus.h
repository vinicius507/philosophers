/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:39:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 18:21:05 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/shm.h>
# include <semaphore.h>

# define UNLIMITED_MEALS -1
# define SOMEONE_DIED "/someone_died"
# define SOMEONE_DIED_LOCK "/someone_died_lock"

typedef struct s_data
{
	int		n;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals;
	long	start_time;
	sem_t	*someone_died;
	sem_t	*someone_died_lock;
}	t_data;

/**
 * @struct s_philo
 * @brief Structure representing a philosopher in the simulation.
 * @var s_philo::id The id of the philosopher
 * @var s_philo::data The data of the simulation
 * @var s_philo::meals The number of meals the philosopher had
 * @var s_philo::last_meal The time of the last meal of the philosopher
 */
typedef struct s_philo
{
	int		id;
	t_data	*data;
	int		meals;
	long	last_meal;
}	t_philo;

int		ft_streq(const char *s1, const char *s2);

int		error(const char *err_msg);

void	argparse(int argc, char **argv, t_data *data);

sem_t	*new_semaphore(const char *name, int value);

long	get_time_in_ms(void);

long	get_time_since(long start);

void	clear_philosophers(t_philo **philosophers);

t_philo	**spawn_philosophers(int n);

int		starved(t_philo *philo);

int		check_someone_died(t_data *data);

void	die(t_philo *philo);

void	simulation(t_philo **philos, t_data *data);

#endif
