/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 21:39:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/08 15:38:45 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# define UNLIMITED_MEALS -1

typedef struct s_data
{
	int		n;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		meals;
	long	start_time;
	int		someone_died;
}	t_data;

int		ft_streq(const char *s1, const char *s2);

int		error(const char *err_msg);

void	argparse(int argc, char **argv, t_data *data);

#endif
