/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:37 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:52:03 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_is_map_rectangle(t_list *lines)
{
	size_t		width;
	t_list_elem	*current_el;

	current_el = lines->top;
	if (!current_el)
		return (-1);
	width = ft_strlen(current_el->data);
	while (current_el)
	{
		if (ft_strlen(current_el->data) != width)
			return (-1);
		current_el = current_el->next;
	}
	return (0);
}

static int	ft_check_map_char(t_list *lines)
{
	t_list_elem	*current_el;
	char		*line;
	char		c;
	size_t		idx;

	current_el = lines->top;
	while (current_el)
	{
		line = current_el->data;
		idx = 0;
		while (line[idx])
		{
			c = line[idx];
			if (!(c == '0' || c == '1' || c == 'P' || c == 'E' || c == 'C'))
				return (-1);
			idx++;
		}
		current_el = current_el->next;
	}
	return (0);
}

static int	ft_check_map_tile(t_list *lines)
{
	t_list_elem	*current_el;
	char		*line;
	size_t		idx;
	t_byte		tiles;

	tiles = 0;
	current_el = lines->top;
	while (current_el)
	{
		line = current_el->data;
		idx = 0;
		while (line[idx])
		{
			ft_set_flag(&tiles, line[idx]);
			idx++;
		}
		current_el = current_el->next;
	}
	if (tiles == 0x7)
		return (0);
	else
		return (-1);
}

static int	ft_check_map_border(t_list *lines)
{
	size_t		width;
	size_t		idx;

	idx = 0;
	width = ft_strlen(lines->top->data);
	while (((char *)(lines->top->data))[idx])
	{
		if (((char *)(lines->top->data))[idx] != '1')
			return (-1);
		idx++;
	}
	idx = 0;
	while (((char *)(lines->bottom->data))[idx])
	{
		if (((char *)(lines->bottom->data))[idx] != '1')
			return (-1);
		idx++;
	}
	if (ft_check_side_border(lines->top, width) < 0)
		return (-1);
	return (0);
}

int	ft_check_map(t_list *lines)
{
	if (ft_is_map_rectangle(lines) < 0)
		return (-1);
	if (ft_check_map_char(lines) < 0)
		return (-2);
	if (ft_check_map_tile(lines) < 0)
		return (-3);
	if (ft_check_map_border(lines) < 0)
		return (-4);
	return (0);
}
