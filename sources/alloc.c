/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 19:05:13 by tkomeno           #+#    #+#             */
/*   Updated: 2023/07/05 18:34:11 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	alloc(t_master **m)
{
	if (!alloc_master(m))
		return (false);
	else if (!alloc_data(&((*m)->data)))
		return (false);
	else if (!alloc_philos(&((*m)->data), &((*m)->philos)))
		return (false);
	else if (!alloc_forks(&((*m)->data)))
		return (false);
	return (true);
}

bool alloc_master(t_master **master)
{
	*master = malloc(sizeof(t_master));
	if (*master == NULL)
		return (false);
	return (true);
}

bool	alloc_data(t_data **data)
{
	*data = malloc(sizeof(t_data));
	if (!*data)
		return (false);
	return (true);
}

bool	alloc_philos(t_data **data, t_philo **philos)
{
	int	number_of_philos;

	number_of_philos = (*data)->number_of_philos;
	*philos = malloc(sizeof(t_philo) * number_of_philos);
	if (!*philos)
		return (false);
	return (true);
}

bool	alloc_forks(t_data **data)
{
	int	number_of_philos;

	number_of_philos = (*data)->number_of_philos;
	(*data)->forks = malloc(sizeof(pthread_mutex_t) * number_of_philos);
	if (!(*data)->forks)
		return (false);
	return (true);
}
