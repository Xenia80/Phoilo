/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:31:15 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 21:18:04 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				eat_cnt;
	unsigned long	t_start;
	unsigned long	t_to_die;
	unsigned long	t_to_eat;
	unsigned long	t_to_sleep;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
	t_philo			**phs;
}	t_data;

struct s_philo
{
	int				id;
	int				lfork;
	int				rfork;
	unsigned long	t_lastmeal;
	int				t_eat;
	pthread_t		thd_philo;
	pthread_mutex_t	meallock;
	t_data			*data;
};

int				ft_atoi(const char *str);
int				check_arg(char **av);
void			my_usleep(long long ms);
long			get_time(void);
pthread_mutex_t	*forks_init(int count);
void			grab_forks(t_philo *philo);
void			put_forks(t_philo *philo);
t_data			*init_data(char **av);
t_philo			*init_philo(int i, t_data *data);
void			*philosopher(void *philos);

#endif
