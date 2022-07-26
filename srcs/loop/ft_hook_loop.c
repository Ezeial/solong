/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:29:05 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:29:16 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	render_next_frame(t_instance *instance)
{
	ft_draw_board(instance);
	ft_draw_player(instance);
	mlx_put_image_to_window(
		instance->win_data.mlx,
		instance->win_data.win,
		instance->win_data.winbuffer.img,
		0,
		0
		);
	return (0);
}

void	ft_hook_loop(t_instance *instance)
{
	mlx_loop_hook(instance->win_data.mlx, render_next_frame, instance);
}
