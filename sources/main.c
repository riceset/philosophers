/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:45:12 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/22 18:43:49 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

#include <stdarg.h>

#define PHILO_NUM 2

#define BLACK           "\033[30m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define WHITE           "\033[37m"
#define RESET			"\x1b[0m"

char *join_strs(int count, ...)
{
	int i;
	char *tmp;
	char *result;
	char *current;
	va_list args;

	va_start(args, count);
	i = 0;
	tmp = NULL;
	result = NULL;
	current = NULL;
	while (i < count)
	{
		current = va_arg(args, char *);

		if (result == NULL)
			result = ft_strdup(current);
		else
		{
			tmp = result;
			result = ft_strjoin(tmp, current);
			free(tmp);
		}

		if (result == NULL)
		{
			va_end(args);
			return (NULL);
		}
		i++;
	}
	va_end(args);

	return (result);
}

char *new_color(void)
{
	static int color_code = 31;

	if (++color_code == 36)
		color_code = 31;

	return (join_strs(3, "\x1b[", ft_itoa(color_code), "m"));
}

void *routine(void *arg)
{
	int *number;

	number = (int *) arg;

	printf("%s%s%s\n", RED, join_strs(3, "Philosopher ",
				ft_itoa(*number), " is eating."), RESET);
	printf("%s%s%s\n", GREEN, join_strs(3, "Philosopher ",
				ft_itoa(*number), " is sleeping."), RESET);
	printf("%s%s%s\n", BLUE, join_strs(3, "Philosopher ",
				ft_itoa(*number), " is thinking."), RESET);

	return (NULL);
}


int main(void)
{
	pthread_t *philos;

	philos = malloc(sizeof(pthread_t *) * PHILO_NUM);

	for (int i = 0; i < PHILO_NUM; i++)
	{
		if (pthread_create(&philos[i], NULL, routine, &i))
			return (1);
	}

	for (int i = 0; i < PHILO_NUM; i++)
	{
		if (pthread_join(philos[i], NULL))
			return (1);
	}

	return (0);
}
