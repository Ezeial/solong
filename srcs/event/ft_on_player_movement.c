/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_player_movement.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:11:20 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:11:54 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

typedef struct idx {
	size_t	x;
	size_t	y;
}	t_idx;

static void	set_idx(t_idx *idx, size_t x, size_t y)
{
	idx->x = x;
	idx->y = y;
}

static t_idx	ft_get_next_pos(int keycode, t_instance *instance)
{
	t_idx	next_pos;

	if (keycode == K_W)
		set_idx(&next_pos, instance->player.x, instance->player.y - 1);
	if (keycode == K_S)
		set_idx(&next_pos, instance->player.x, instance->player.y + 1);
	if (keycode == K_A)
		set_idx(&next_pos, instance->player.x - 1, instance->player.y);
	if (keycode == K_D)
		set_idx(&next_pos, instance->player.x + 1, instance->player.y);
	return (next_pos);
}

int	ft_is_there_still_collectible(t_instance *instance)
{
	size_t	x_idx;
	size_t	y_idx;

	y_idx = 0;
	while (y_idx < instance->map_data.height)
	{
		x_idx = 0;
		while (x_idx < instance->map_data.width)
		{
			if (instance->map_data.map[y_idx][x_idx] == COLLECTIBLE)
				return (1);
			x_idx++;
		}
		y_idx++;
	}
	return (0);
}

void	ft_on_player_movement(int keycode, t_instance *instance)
{
	t_idx	next_pos;

	if (keycode != K_W && keycode != K_A && keycode != K_S && keycode != K_D)
		return ;
	next_pos = ft_get_next_pos(keycode, instance);
	if (instance->map_data.map[next_pos.y][next_pos.x] == WALL)
		return ;
	if (instance->map_data.map[next_pos.y][next_pos.x] == COLLECTIBLE)
		instance->map_data.map[next_pos.y][next_pos.x] = EMPTY;
	instance->player.mov++;
	instance->player.x = next_pos.x;
	instance->player.y = next_pos.y;
	printf("Movement : %ld\n", instance->player.mov);
	if (instance->map_data.map[next_pos.y][next_pos.x] == EXIT
			&& !ft_is_there_still_collectible(instance))
		ft_exit_program(instance);
}
