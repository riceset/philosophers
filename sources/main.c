/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:24:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/24 22:22:57 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data *data;

	data = NULL;
	if (!init(argc, argv, &data))
		return (1);

	printf("%d\n", data->time_to_die);

	if (data->times_each_philo_must_eat == NOT_SET)
		while (true)
		{
		}
	// else
	// 	while (data->times_ate < data->times_each_philo_must_eat)
	// 	{
	// 	}
	return (0);
}
