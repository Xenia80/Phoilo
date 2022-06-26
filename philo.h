/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:31:15 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:33:53 by pnona            ###   ########.fr       */
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
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}				t_data;

typedef struct s_philo
{
	int				id;
	int				left;
	int				right;
	int				t_eat;
	unsigned long	lasteat;
	pthread_t		phi;
	pthread_mutex_t	mute;
	t_data			*data;
}				t_philo;

int				ft_error(int i);
long			get_time(void);
void			my_usleep(long long ms);
int				ft_atoi(const char *str);
int				check_arg(char **argv);
t_data			*init_data(char **argv);
t_philo			*init_philo(int i, t_data *data);
pthread_mutex_t	*forks_init(int num);
t_philo			*init_philo(int i, t_data *data);
void			init_threads(t_data *data);
void			grab_forks(t_philo *philo);
void			put_forks(t_philo *philo);
int				check_numeat(t_data *data);
void			if_death(t_data *data);
void			*philosopher(void *philos);

#endif
