/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 13:20:16 by tkomeno           #+#    #+#             */
/*   Updated: 2023/06/30 13:20:53 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void print_current_philo(t_philo *philo)
{
	printf("ID: %d\n", philo->id);
}

bool debug(void)
{
	printf("ERROR!!!!!!!!!!\n");
	return (false);
}

