/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:24:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/27 19:06:08 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_current_philo(t_philo *philo)
{
	printf("ID: %d\n", philo->id);
}

void	*routine(void *arg)
{
	(void)arg;
	t_philo *philo;

	philo = (t_philo *)arg;

	print_current_philo(philo);

	return (NULL);
}

bool debug(void)
{
	printf("ERROR!!!!!!!!!!\n");
	return (false);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_philo *philos;

	philos = NULL;
	data = NULL;
	if (!init(argc, argv, &data, &philos))
		return (EXIT_FAILURE);
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
