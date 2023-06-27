/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:05:13 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/27 19:05:19 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool alloc_data(t_data **data)
{
	*data = malloc(sizeof(t_data) * 1);
	if (!*data)
		return (false);
	return (true);
}

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

