/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:30:36 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:30:38 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	*init_data(char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->num_philo = ft_atoi(argv[1]);
	data->t_die = ft_atoi(argv[2]);
	data->t_eat = ft_atoi(argv[3]);
	data->t_sleep = ft_atoi(argv[4]);
	data->eat_raz = -1;
	if (argv[5])
	{
		data->eat_raz = ft_atoi(argv[5]);
		if (data->eat_raz <= 0)
			return (NULL);
	}
	return (data);
}

pthread_mutex_t	*forks_init(int num)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = malloc(sizeof(pthread_mutex_t) * num);
	if (!forks)
		return (NULL);
	i = 0;
	while (i < num)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
	return (forks);
}

t_philo	*init_philo(int i, t_data *data)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i + 1;
	philo->data = data;
	philo->t_eat = data->eat_raz;
	philo->right = i;
	philo->left = (i + data->eat_raz - 1) % data->num_philo;
	if (i == 0)
	{
		philo->left = i;
		philo->right = (i + data->eat_raz - 1) % data->num_philo;
	}
	pthread_mutex_init(&philo->mute, NULL);
	data->forks = forks_init(data->num_philo);
	if (!data->forks)
	{
		free(data);
		return (NULL);
	}
	pthread_mutex_init(&data->print, NULL);
	return (philo);
}

void	init_threads(t_data *data)
{
	t_philo		*philo;
	int			i;

	i = -1;
	data->philo = malloc(sizeof(t_philo) * data->num_philo);
	data->t_start = get_time();
	while (++i < data->num_philo)
	{
		philo = init_philo(i, data);
		data->philo[i] = philo;
		pthread_create(&data->philo[i]->phi, NULL, philosopher,
			(void *) philo);
	}
	i = -1;
	while (++i < data->num_philo)
		pthread_detach(data->philo[i]->phi);
}