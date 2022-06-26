/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lifecycle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:31:41 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:31:42 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*eatcheck(void *_data)
{
	int		i;
	t_data	*data;

	data = (t_data *)_data;
	i = -1;
	sem_wait(data->print_sem);
	while (++i < data->num_philo)
	{
		sem_post(data->print_sem);
		sem_wait(data->eat);
		sem_wait(data->print_sem);
	}
	sem_post(data->stop_sim);
	return (NULL);
}

void	*deathcheck(void *_data)
{
	t_data	*data;

	data = (t_data *)_data;
	while (1)
	{
		if (get_time() - data->philo.t_lastmeal >= data->t_to_die)
		{
			sem_wait(data->print_sem);
			printf("%lu %d died\n", get_time() - data->t_start,
				data->philo.id);
			stop_simulation(data);
			sem_post(data->stop_sim);
			exit(EXIT_SUCCESS);
		}
		my_usleep(10);
	}
	return (NULL);
}

void	eating(t_data *data)
{
	sem_wait(data->fork_sem);
	sem_wait(data->fork_sem);
	print_fork(data);
	sem_wait(data->print_sem);
	printf("%lu %d is eating\n", get_time() - data->t_start,
		data->philo.id);
	sem_post(data->print_sem);
	data->philo.t_lastmeal = get_time();
	data->philo.t_eat++;
	my_usleep(data->t_to_eat);
	if (data->philo.t_eat == data->eat_cnt)
		sem_post(data->eat);
	sem_post(data->fork_sem);
	sem_post(data->fork_sem);
}

void	sleep_think(t_data *data)
{
	sem_wait(data->print_sem);
	printf("%lu %d is sleeping\n", get_time() - data->t_start,
		data->philo.id);
	sem_post(data->print_sem);
	my_usleep(data->t_to_sleep);
	sem_wait(data->print_sem);
	printf("%lu %d is thinking\n", get_time() - data->t_start,
		data->philo.id);
	sem_post(data->print_sem);
}

void	lifecycle(t_data *data)
{
	data->t_start = get_time();
	while (1)
	{
		eating(data);
		sleep_think(data);
	}
}
