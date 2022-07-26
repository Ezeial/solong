/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_assets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:09:33 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:09:39 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_destroy_assets(t_instance *instance)
{
	mlx_destroy_image(instance->win_data.mlx, instance->assets.collectible.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.wall.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.player.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.exit.img);
	mlx_destroy_image(instance->win_data.mlx, instance->assets.empty.img);
}
