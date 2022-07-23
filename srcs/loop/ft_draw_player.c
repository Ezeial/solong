/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:29:02 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:29:03 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_draw_player(t_instance *instance)
{
	put_img_to_buffer(
		&(instance->assets.player),
		&(instance->win_data.winbuffer),
		instance->player.x * TILE_WIDTH,
		instance->player.y * TILE_HEIGHT
		);
}
