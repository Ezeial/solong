/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:53:08 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:53:37 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int ac, char **av)
{
	t_instance	instance;

	if (ft_parse(ac, av, &(instance.map_data)) < 0)
	{
		printf("Error\nParsing failed\n");
		return (1);
	}
	if (ft_init(&instance) < 0)
	{
		printf("Error\nInitialization failed\n");
		return (1);
	}
	ft_hook_events(&instance);
	ft_hook_loop(&instance);
	mlx_loop(instance.win_data.mlx);
	return (0);
}
