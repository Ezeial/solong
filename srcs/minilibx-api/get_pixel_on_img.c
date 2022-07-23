/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pixel_on_img.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:29:19 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:29:22 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	*get_pixel_on_img(t_img_data *img_data, int x, int y)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			* (img_data->bits_per_pixel / 8));
	return ((int *)dst);
}
