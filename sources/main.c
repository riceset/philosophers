/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomeno <tkomeno@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:24:44 by tkomeno           #+#    #+#             */
/*   Updated: 2023/07/05 18:37:12 by tkomeno          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_master	*master;

	if (incorrect_input(argc, argv))
		return (EXIT_FAILURE);
	else if (!alloc(&master))
		return (EXIT_FAILURE);
	else if (!init(argc, argv, &master))
		return (EXIT_FAILURE);;
	return (EXIT_SUCCESS);
}
