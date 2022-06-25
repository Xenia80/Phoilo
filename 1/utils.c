/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:26:11 by lloko             #+#    #+#             */
/*   Updated: 2022/06/25 00:12:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int i)
{
	if (i == 1)
		printf("Wrong arguments: you should use positive integers\n");
	if (i == 2)
		printf("Wrong numbers of arguments: use number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]"\n);
	if (i == 3)
		printf("Memory was not allocated\n");
	return (0);
}

long	get_time(void)
{
	t_time	check_time;

	gettimeofday(&check_time, NULL);
	return ((check_time.tv_sec * 1000) + (check_time.tv_usec / 1000));
}

void	my_usleep(long long ms)
{
	long long	t;
	
	t = 0;
	t = get_time();
	while ((get_time() - t) < ms)
		usleep(ms / 10);
}
