/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 16:46:38 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/24 22:19:08 by tkomeno          ###   ########.fr       */
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
	int				times_ate;
	pthread_mutex_t	*forks;
}					t_data;

bool				only_digits(char *str);
int					error_handler(char *message, int code);
int					incorrect_input(int argc, char **argv);
bool				init_data(t_data **data, int argc, char **argv);
bool				init(int argc, char **argv, t_data **data);
void				philo_eat(void);
void				philo_sleep(void);
void				philo_think(void);
long long			get_time(void);

#endif
