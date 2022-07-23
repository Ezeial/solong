#include "solong.h"

void ft_init_player(t_player *player, t_map_data *map_data)
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