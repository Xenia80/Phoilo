/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:24:34 by lloko             #+#    #+#             */
/*   Updated: 2022/06/25 00:11:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int			i;
	long long	sign;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = 1 - 2 * (str[i++] == '-');
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result * sign < (-9223372036854775807L))
			return (0);
		if (result * sign > (9223372036854775807L))
			return (-1);
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

static int	arg_is_num(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' '
		|| str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

static int	arg_is_int(char *str)
{
	if (ft_atoi(str) < 0 || ft_atoi(str) > 2147483647)
		return (1);
	return (0);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!arg_is_int(argv[i]) || !arg_is_num(argv[i]))
			return (ft_error(1));
		i++;
	}
	return (0);
}
