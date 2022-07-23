/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:12:43 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:15:52 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_load_img(void *mlx, t_img_data *img_data, char *path)
{
	img_data->img = mlx_xpm_file_to_image(mlx, path,
			&(img_data->width), &(img_data->height));
	img_data->addr = mlx_get_data_addr(
			img_data->img,
			&(img_data->bits_per_pixel),
			&(img_data->line_length),
			&(img_data->endian)
			);
}

void	ft_load_assets(t_instance *instance)
{
	ft_load_img(instance->win_data.mlx, &(instance->assets.collectible),
		"assets/collectible.xpm");
	ft_load_img(instance->win_data.mlx, &(instance->assets.player),
		"assets/player.xpm");
	ft_load_img(instance->win_data.mlx, &(instance->assets.wall),
		"assets/wall.xpm");
	ft_load_img(instance->win_data.mlx, &(instance->assets.exit),
		"assets/exit.xpm");
	ft_load_img(instance->win_data.mlx, &(instance->assets.empty),
		"assets/empty.xpm");
}
