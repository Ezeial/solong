/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:12:00 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:12:09 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_init_player(t_player *player, t_map_data *map_data)
{
	size_t	x_idx;
	size_t	y_idx;

	y_idx = 0;
	while (y_idx < map_data->height)
	{
		x_idx = 0;
		while (x_idx < map_data->width)
		{
			if (map_data->map[y_idx][x_idx] == PLAYER)
			{
				player->x = x_idx;
				player->y = y_idx;
				player->mov = 0;
				return ;
			}
			x_idx++;
		}
		y_idx++;
	}	
}
