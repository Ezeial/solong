/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:12:42 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:53:46 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_init(t_instance	*instance)
{
	if (ft_init_win_data(&(instance->win_data),
			TILE_WIDTH * instance->map_data.width,
			TILE_HEIGHT * instance->map_data.height) < 0)
	{
		ft_destroy_map_data(&(instance->map_data));
		return (-1);
	}
	ft_load_assets(instance);
	ft_init_player(&(instance->player), &(instance->map_data));
	return (0);
}
