/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel_to_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:29:44 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:30:28 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	put_pixel_to_img(t_img_data *img, int x, int y, int color)
{
	if ((x < 0 || img->width < x) || (y < 0 || img->height < y)
		|| (unsigned int)color == 0xff000000)
		return ;
	*get_pixel_on_img(img, x, y) = color;
}
