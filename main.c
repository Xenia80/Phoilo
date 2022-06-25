/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:08:00 by lloko             #+#    #+#             */
/*   Updated: 2022/06/25 00:28:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

check_numeat

if_death

int main (int argc, char **argv)
{
	t_data *data;
	
	if (argc < 5 || argc > 6)
		return (ft_error(2));
	if (!check_arg(argc, argv))
		return (0);
	data = init_data(argv);
	if (!data)
		return (0);
	init_threads(data);
	if_death(data);
	return (0);
}