/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:03:12 by lloko             #+#    #+#             */
/*   Updated: 2022/06/25 00:34:51 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	unsigned long	t_eat;
	unsigned long	t_die;
	unsigned long	t_sleep;
	unsigned long	t_start;
	int				num_philo;
	int				eat_raz;
	t_philo			**philo;
}				t_data;

typedef struct timeval
{
	long	tv_sec;
	long	tv_usec;
}				t_time;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	int				t_eat;
	unsigned long	lasteat;
	pthread_t		phi;
	pthread_mutex_t	mute;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_data			*data;
	t_time			check_time;
}				t_philo

int		ft_error(int i);
long	get_time(void);
void	my_usleep(long long ms);
int		check_arg(int argc, char **argv, t_data *data);
t_data	*init_data(char **argv);
t_philo	*init_philo(int i, t_data *data);

#endif
