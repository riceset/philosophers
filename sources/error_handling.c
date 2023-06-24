/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:55:46 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/24 18:55:59 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
