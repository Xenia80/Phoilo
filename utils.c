/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnona <pnona@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 20:31:25 by pnona             #+#    #+#             */
/*   Updated: 2022/06/26 20:33:09 by pnona            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_error(int i)
{
	if (i == 1)
		printf("Wrong arguments: you should use positive integers\n");
	if (i == 2)
		printf("Wrong numbers of arguments\n");
	return (0);
}

long	get_time(void)
{
	struct timeval	check_time;

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
