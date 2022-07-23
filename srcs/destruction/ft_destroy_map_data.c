/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_map_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:09:43 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:09:47 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_destroy_map_data(t_map_data *map_data)
{
	size_t	y;

	if (!map_data->map)
		return ;
	y = 0;
	while (y < map_data->height)
	{
		free(map_data->map[y]);
		y++;
	}
	free(map_data->map);
	map_data->map = NULL;
}
