/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_data.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:45:25 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:45:34 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_init_map_data(t_list *lines, t_map_data *map_data)
{
	t_list_elem	*current_elem;
	size_t		y;

	map_data->width = ft_strlen((char *)(lines->top->data));
	map_data->height = ft_lstsize(lines);
	map_data->map = malloc(sizeof(char *) * map_data->height);
	if (!map_data->map)
		return (-1);
	current_elem = lines->top;
	y = 0;
	while (current_elem && y < map_data->height)
	{
		map_data->map[y] = ft_strdup(current_elem->data);
		if (!map_data->map[y])
		{
			free(map_data->map);
			return (-1);
		}
		current_elem = current_elem->next;
		y++;
	}
	return (0);
}
