/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:16:01 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:28:04 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

typedef struct s_idx {
	size_t	x;
	size_t	y;
}	t_idx;

void	ft_draw_board(t_instance *instance)
{
	t_idx		i;
	t_img_data	*wbf;

	wbf = &(instance->win_data.winbuffer);
	i.y = 0;
	while (i.y < instance->map_data.height)
	{
		i.x = 0;
		while (i.x < instance->map_data.width)
		{
			put_img_to_buffer(&(instance->assets.empty), wbf,
				i.x * TILE_WIDTH, i.y * TILE_HEIGHT);
			if (instance->map_data.map[i.y][i.x] == WALL)
				put_img_to_buffer(&(instance->assets.wall),
					wbf, i.x * TILE_WIDTH, i.y * TILE_HEIGHT);
			if (instance->map_data.map[i.y][i.x] == COLLECTIBLE)
				put_img_to_buffer(&(instance->assets.collectible), wbf,
					i.x * TILE_WIDTH, i.y * TILE_HEIGHT);
			if (instance->map_data.map[i.y][i.x] == EXIT)
				put_img_to_buffer(&(instance->assets.exit), wbf,
					i.x * TILE_WIDTH, i.y * TILE_HEIGHT);
			i.x++;
		}
		i.y++;
	}
}
