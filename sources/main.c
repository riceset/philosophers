/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:24:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/27 18:32:37 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	alloc_philos(t_data **data, t_philo **philos)
{
	*philos = malloc(sizeof(t_philo) * (*data)->number_of_philos);
	if (!philos)
		return (false);
	return (true);
}

bool	alloc_forks(t_data **data)
{
	(*data)->forks = malloc(sizeof(pthread_mutex_t)
			* (*data)->number_of_philos);
	if (!(*data)->forks)
		return (false);
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

void	*routine(void *arg)
{
	(void)arg;
	// t_philo *philo;

	// philo = (t_philo *)arg;

	return (NULL);
}

void print_current_philo(t_philo *philos)
{
	printf("ID: %d\n", philos->id);
	printf("LF: %p\n", philos->left_fork);
	printf("RF: %p\n", philos->right_fork);
}

bool	init_philos(t_data **data, t_philo **philos)
{
	int	i;

	i = 0;
	while (i < (*data)->number_of_philos)
	{
		(*philos)[i].id = i + 1;
		(*philos)[i].left_fork = &(*data)->forks[i];
		(*philos)[i].right_fork = &(*data)->forks[(i + 1)
			% (*data)->number_of_philos];
		print_current_philo(&(*philos)[i]);
		// if (pthread_create(&(philos)[i]->thread, NULL, routine,
		// 		&philos[i]) != 0)
		// 	return (false);
		i++;
	}

	// i = 0;
	// while (i < (*data)->number_of_philos)
	// {
	// 	pthread_join(philos[i]->thread, NULL);
	// 	i++;
	// }
	return (true);
}

bool debug(void)
{
	printf("ERROR!!!!!!!!!!\n");
	return (false);
}

//TODO: Instead of returning false, free all the allocated
//memory.
bool	init2(t_data **data, t_philo **philos)
{
	if (!alloc_philos(data, philos))
		return (debug());
	else if (!alloc_forks(data))
		return (debug());
	else if (!init_forks(data))
		return (debug());
	else if (!init_philos(data, philos))
		return (debug());
	return (true);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo *philos;

	philos = NULL;
	data = NULL;
	if (!init(argc, argv, &data))
		return (EXIT_FAILURE);
	if (!init2(&data, &philos))
		return (EXIT_FAILURE);
	// if (!init_philos(data, philos))
	// 	return (EXIT_FAILURE);
	// if (!create_threads(data, philos))
	// 	return (EXIT_FAILURE);
	// if (!join_threads(data, philos))
	// 	return (EXIT_FAILURE);
	// free(philos);
	// free(data);
	return (EXIT_SUCCESS);
}

// if (data->times_each_philo_must_eat == NOT_SET)
// 	while (true)
// 	{
//
// 	}
// else
// 	while (data->times_ate < data->times_each_philo_must_eat)
// {
//
// }
