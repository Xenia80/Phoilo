/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   for_forks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:30:27 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:33:43 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grab_forks(t_philo *philo)
{
	pthread_mutex_lock(&philo->data->forks[philo->left]);
	pthread_mutex_lock(&philo->data->forks[philo->right]);
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d taken forks\n", get_time() - philo->data->t_start, philo->id);
	pthread_mutex_unlock(&philo->data->print);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left]);
	pthread_mutex_unlock(&philo->data->forks[philo->right]);
}
