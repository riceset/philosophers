/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:52:48 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/27 17:39:54 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool init(int argc, char **argv, t_data **data)
{
	if (incorrect_input(argc, argv))
		return (false);

	*data = malloc(sizeof(t_data) * 1);
	if (!*data)
		return (false);

	if (!init_data(data, argc, argv))
		return (false);

	return (true);
}

bool	init_data(t_data **data, int argc, char **argv)
{
	(*data)->start_time = get_time();
	(*data)->number_of_philos = ft_atoi(argv[1]);
	(*data)->time_to_die = ft_atoi(argv[2]);
	(*data)->time_to_eat = ft_atoi(argv[3]);
	(*data)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data)->times_each_philo_must_eat = ft_atoi(argv[5]);
	else
		(*data)->times_each_philo_must_eat = NOT_SET;
	return (true);
}
