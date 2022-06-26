/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:30:27 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 21:16:33 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->lfork]);
	pthread_mutex_lock(&philo->data->forks[philo->rfork]);
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d has taken a fork\n", get_time() - philo->data->t_start,
		philo->id);
	pthread_mutex_unlock(&philo->data->print);
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d has taken a fork\n", get_time() - philo->data->t_start,
		philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->lfork]);
	pthread_mutex_unlock(&philo->data->forks[philo->rfork]);
}

pthread_mutex_t	*forks_init(int count)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * count);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < count)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

void	free_for_forks(pthread_mutex_t *forks, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
}
