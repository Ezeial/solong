#include "solong.h"

void	ft_draw_board(t_instance *instance)
{
	size_t		x_idx;
	size_t		y_idx;

	y_idx = 0;
	while (y_idx < instance->map_data.height)
	{
		x_idx = 0;
		while (x_idx < instance->map_data.width)
		{
			put_img_to_buffer(&(instance->assets.empty), &(instance->win_data.winbuffer), x_idx * TILE_WIDTH, y_idx * TILE_HEIGHT);
			if (instance->map_data.map[y_idx][x_idx] == WALL)
				put_img_to_buffer(&(instance->assets.wall), &(instance->win_data.winbuffer), x_idx * TILE_WIDTH, y_idx * TILE_HEIGHT);
			if (instance->map_data.map[y_idx][x_idx] == COLLECTIBLE)
				put_img_to_buffer(&(instance->assets.collectible), &(instance->win_data.winbuffer), x_idx * TILE_WIDTH, y_idx * TILE_HEIGHT);
			if (instance->map_data.map[y_idx][x_idx] == EXIT)
				put_img_to_buffer(&(instance->assets.exit), &(instance->win_data.winbuffer), x_idx * TILE_WIDTH, y_idx * TILE_HEIGHT);
			x_idx++;
		}
		y_idx++;
	}
}