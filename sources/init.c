/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 20:52:48 by tkomeno           #+#    #+#             */
/*   Updated: 2023/07/04 21:47:59 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool init(int argc, char **argv, t_data **data, t_philo **philos)
{
	if (incorrect_input(argc, argv))
		return (false);
	else if (!alloc_data(data))
		return (false);
	else if (!alloc_philos(data, philos))
		return (false);
	else if (!alloc_forks(data))
		return (false);
	else if (!init_data(data, argc, argv))
		return (false);
	else if (!init_philos(data, philos))
		return (false);
	else if (!init_forks(data))
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

bool	init_forks(t_data **data)
{
	int	i;

	i = 0;
	while (i < (*data)->number_of_philos)
	{
		if (pthread_mutex_init(&(*data)->forks[i], NULL) != 0)
			return (false);
		i++;
	}
	return (true);
}

bool	init_philos(t_data **data, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < (*data)->number_of_philos)
	{
		(*philos)[i].is_death = false;
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = &(*data)->forks[i];
		(*philos)[i].right_fork = &(*data)->forks[(i + 1)
			% (*data)->number_of_philos];
		(*philos)[i].data = *data;
		pthread_create(&(*philos)[i].thread, NULL, routine, &(*philos)[i]);
		i++;
	}

	i = 0;
	while (i < (*data)->number_of_philos)
	{
		pthread_join((*philos)[i].thread, NULL);
		i++;
	}
	return (true);
}
