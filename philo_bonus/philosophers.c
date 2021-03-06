/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:31:57 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:31:59 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	start_threads(t_data *data)
{
	int		i;

	data->t_start = get_time();
	i = -1;
	while (++i < data->num_philo)
	{
		data->philo.id = i + 1;
		data->philos_pid[i] = fork();
		if (data->philos_pid[i] == 0)
		{
			init_deathcheck(data);
			lifecycle(data);
		}
		if (data->philos_pid[i] == -1)
		{
			while (--i >= 0)
				kill(data->philos_pid[i], SIGINT);
			return (1);
		}
	}
	sem_wait(data->stop_sim);
	return (0);
}

void	stop_simulation(t_data *data)
{
	int		i;

	i = -1;
	while (++i < data->num_philo)
		kill(data->philos_pid[i], SIGINT);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 5 || ac > 6)
		return (0);
	if (!check_arg(av))
		return (1);
	if (init_data(ac, av, &data))
		return (2);
	if (start_threads(&data))
		return (3);
	stop_simulation(&data);
	return (0);
}
