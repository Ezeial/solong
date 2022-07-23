#include "solong.h"

void ft_destroy_assets(t_instance *instance)
{
	mlx_destroy_image(instance->win_data.mlx, instance->assets.collectible.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.wall.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.player.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.exit.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.empty.img);
}