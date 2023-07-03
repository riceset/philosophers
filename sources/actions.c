/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:29:58 by tkomeno           #+#    #+#             */
/*   Updated: 2023/07/03 19:44:11 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		printf("%lld %d has taken a fork\n", get_time()
				- philo->data->start_time, philo->id);
		pthread_mutex_lock(philo->left_fork);
		printf("%lld %d has taken a fork\n", get_time()
				- philo->data->start_time, philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%lld %d has taken a fork\n", get_time()
				- philo->data->start_time, philo->id);
		pthread_mutex_lock(philo->right_fork);
		printf("%lld %d has taken a fork\n", get_time()
				- philo->data->start_time, philo->id);
	}
}

void	release_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	philo_eat(t_philo *philo)
{
	printf("%lld %d is eating\n", get_time() - philo->data->start_time,
			philo->id);
	usleep(philo->data->time_to_eat * 1000);
}

void	philo_sleep(t_philo *philo)
{
	printf("%lld %d is sleeping\n", get_time() - philo->data->start_time,
			philo->id);
	usleep(philo->data->time_to_sleep * 1000);
}
void	philo_think(t_philo *philo)
{
	printf("%lld %d is thinking\n", get_time() - philo->data->start_time,
			philo->id);
	usleep(1000);
}
