/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_to_buffer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:29:23 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:29:32 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_img_to_buffer(t_img_data *img, t_img_data *buffer, int x, int y)
{
	int	x_idx;
	int	y_idx;

	y_idx = 0;
	while (y_idx < img->height && y + y_idx < buffer->height)
	{
		x_idx = 0;
		while (x_idx < img->width && x + x_idx < buffer->width)
		{
			put_pixel_to_img(buffer, x + x_idx, y + y_idx,
				*get_pixel_on_img(img, x_idx, y_idx));
			x_idx++;
		}
		y_idx++;
	}
}
