/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:19:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/07/03 19:45:09 by tkomeno          ###   ########.fr       */
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
		get_forks(philo);
		philo_eat(philo);
		release_forks(philo);
		philo_sleep(philo);
		philo_think(philo);
		i++;
	}
	return (NULL);
}
