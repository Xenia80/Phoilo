/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_acts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:31:07 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:31:09 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	eat_philo(t_philo *philo)
{
	grab_forks(philo);
	pthread_mutex_lock(&philo->mute);
	philo->lasteat = get_time();
	pthread_mutex_unlock(&philo->mute);
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d is eating\n", philo->lasteat - philo->data->t_start,
		philo->id);
	pthread_mutex_unlock(&philo->data->print);
	my_usleep(philo->data->t_eat);
	pthread_mutex_lock(&philo->mute);
	if (philo->t_eat > 0)
		philo->t_eat--;
	pthread_mutex_unlock(&philo->mute);
}

static void	sleep_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d is sleeping\n", get_time() - philo->data->t_start,
		philo->id);
	pthread_mutex_unlock(&philo->data->print);
	put_forks(philo);
	my_usleep(philo->data->t_sleep);
}

static void	think_philo(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d is thinking\n", get_time() - philo->data->t_start,
		philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	*philosopher(void *philos)
{
	t_philo		*philo;

	philo = (t_philo *)philos;
	pthread_mutex_lock(&philo->mute);
	philo->lasteat = get_time();
	pthread_mutex_unlock(&philo->mute);
	if (philo->id % 2 == 0)
		usleep(10);
	while (philo->t_eat != 0)
	{
		eat_philo(philo);
		sleep_philo(philo);
		think_philo(philo);
		usleep(10);
	}
	return (NULL);
}
