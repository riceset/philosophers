/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:19:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/30 13:19:51 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	(void)arg;
	t_philo *philo;

	philo = (t_philo *)arg;
	printf("philos_num:%d\n", philo->data->number_of_philos);

	return (NULL);
}
