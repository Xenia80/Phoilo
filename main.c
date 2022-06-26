/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:30:53 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:30:57 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_numeat(t_data *data)
{
	int	i;
	int	sum;

	i = -1;
	sum = 0;
	while (++i < data->num_philo)
	{
		pthread_mutex_lock(&data->philo[i]->mute);
		sum += data->philo[i]->t_eat;
		pthread_mutex_unlock(&data->philo[i]->mute);
	}
	if (sum == 0)
		return (1);
	return (0);
}

void	if_death(t_data *data)
{
	int				i;
	unsigned long	lastmeal;

	while (1)
	{
		i = -1;
		while (++i < data->num_philo)
		{
			pthread_mutex_lock(&data->philo[i]->mute);
			lastmeal = data->philo[i]->lasteat;
			pthread_mutex_unlock(&data->philo[i]->mute);
			if (get_time() - lastmeal >= data->t_die)
			{
				pthread_mutex_lock(&data->print);
				printf("%lu %d died\n", get_time() - data->t_start,
					data->philo[i]->id);
				return ;
			}
		}
		if (check_numeat(data))
			return ;
		usleep(10);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 5 || argc > 6)
		return (ft_error(2));
	if (!check_arg(argv))
		return (0);
	data = init_data(argv);
	if (!data)
		return (0);
	init_threads(data);
	if_death(data);
	return (0);
}
