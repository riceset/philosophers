/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:46:38 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/27 19:03:21 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define USAGE "usage: ./philo <number_of_philosophers> \
<time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_times_each_philosopher_must_eat]"

# define NOT_SET (-1)

# include "libft.h"
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data
{
	int				number_of_philos;
	long long		start_time;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				times_each_philo_must_eat;
	pthread_mutex_t	*forks;
}					t_data;

typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}					t_philo;

bool				only_digits(char *str);
int					error_handler(char *message, int code);
int					incorrect_input(int argc, char **argv);
bool				init_data(t_data **data, int argc, char **argv);
void				philo_eat(void);
void				philo_sleep(void);
void				philo_think(void);
long long			get_time(void);
bool				init_philos(t_data **data, t_philo **philos);
void				*routine(void *arg);
bool				alloc_data(t_data **data);
bool				alloc_philos(t_data **data, t_philo **philos);
bool				alloc_forks(t_data **data);
bool				init_forks(t_data **data);
void				print_current_philo(t_philo *philo);
bool				init(int argc, char **argv, t_data **data,
						t_philo **philos);

#endif
