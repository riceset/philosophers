/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:19:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/30 13:49:01 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	int		i;
	t_philo	*philo;
	t_data	*data;

	philo = (t_philo *)arg;
	data = philo->data;
	i = 0;
	while (i < data->times_each_philo_must_eat)
	{
		philo_think(philo->id);
		philo_eat(philo->left_fork, philo->right_fork, philo->id,
				data->time_to_eat);
		philo_sleep(philo->id, data->time_to_sleep);
		i++;
	}
	return (NULL);
}
