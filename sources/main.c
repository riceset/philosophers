/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:24:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/24 18:53:02 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

typedef struct s_data
{
	int number_of_philos;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int times_each_philo_must_eat;
} t_data;

int error_handler(char *message, int code)
{
	printf("philo: %s\n", message);
	return (code);
}

int incorrect_input(int argc, char **argv)
{
	int i;
	int current;

	if (!(5 <= argc && argc <= 6))
		return (error_handler(USAGE, 1));
	i = 1;
	while (i < argc)
	{
		if (!only_digits(argv[i]))
			return (error_handler(USAGE, 1));
		current = ft_atoi(argv[i]);
		if (i == 1 && !(0 < current && current <= 250))
			return (error_handler(USAGE, 1));
		if (i != 1 && current == -1)
			return (error_handler(USAGE, 1));
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	// t_data data;

	if (incorrect_input(argc, argv))
		return (1);

	// data.number_of_philos = ft_atoi(argv[1]);
	// data.time_to_die = ft_atoi(argv[2]);
	// data.time_to_eat = ft_atoi(argv[3]);
	// data.time_to_sleep = ft_atoi(argv[4]);
	// data.times_each_philo_must_eat = ft_atoi(argv[5]);
}
