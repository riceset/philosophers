/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:29:58 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/30 13:47:17 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_eat(pthread_mutex_t *left_fork, pthread_mutex_t *right_fork,
		int id, int time_to_eat)
{
	pthread_mutex_lock(left_fork);
	printf("Philosopher %d has taken the left fork\n", id);
	pthread_mutex_lock(right_fork);
	printf("Philosopher %d has taken the right fork\n", id);
	printf("Philosopher %d is eating\n", id);
	usleep(time_to_eat * 1000);
	pthread_mutex_unlock(right_fork);
	pthread_mutex_unlock(left_fork);
	printf("Philosopher %d has released the forks\n", id);
}

void	philo_sleep(int id, int time_to_sleep)
{
	printf("Philosopher %d is sleeping\n", id);
	usleep(time_to_sleep * 1000);
}
void	philo_think(int id)
{
	printf("Philosopher %d is thinking\n", id);
	usleep(1000);
}
