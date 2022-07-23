/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_win_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:09:51 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:10:02 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_destroy_win_data(t_win_data *win_data)
{
	mlx_destroy_image(win_data->mlx, win_data->winbuffer.img);
	mlx_destroy_window(win_data->mlx, win_data->win);
	free(win_data->mlx);
	win_data->mlx = NULL;
	win_data->win = NULL;
}
