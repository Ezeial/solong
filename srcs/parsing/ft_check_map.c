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
			if (line[idx] == 'E')
				tiles |= 0x1;
			if (line[idx] == 'P')
				tiles |= 0x2;
			if (line[idx] == 'C')
				tiles |= 0x4;
			idx++;
		}
		current_el = current_el->next;
	}
	if (tiles == 0x7)
		return (0);
	else
		return (-1);
}

static int ft_check_map_border(t_list *lines)
{
	size_t		width;
	size_t		idx;
	t_list_elem	*current_el;

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
	current_el = lines->top;
	while (current_el)
	{
		if (((char *)(current_el->data))[0] != '1' ||
				((char *)(current_el->data))[width - 1] != '1')
			return (-1);
		current_el = current_el->next;
	}
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