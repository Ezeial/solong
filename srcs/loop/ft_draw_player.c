#include "solong.h"

void	ft_draw_player(t_instance *instance)
{
	put_img_to_buffer(&(instance->assets.player), &(instance->win_data.winbuffer), instance->player.x * TILE_WIDTH, instance->player.y * TILE_HEIGHT);
}