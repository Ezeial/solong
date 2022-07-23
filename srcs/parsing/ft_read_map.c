/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:45:40 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:51:43 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_trim_newline(char *line, char **trimmed_line, t_list *lines)
{
	*trimmed_line = ft_strtrim(line, "\n");
	free(line);
	if (!*trimmed_line)
	{
		ft_lstclear(lines, free);
		return (-1);
	}
	return (0);
}

int	ft_read_map(char *path, t_list **lines)
{
	int			fd;
	char		*line;
	char		*trimmed_line;
	t_list_elem	*current_el;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	*lines = ft_lstnew();
	line = get_next_line(fd);
	while (line)
	{
		if (ft_trim_newline(line, &trimmed_line, *lines) < 0)
			return (-1);
		current_el = ft_lstcreate_elem(trimmed_line);
		if (!current_el)
		{
			ft_lstclear(*lines, free);
			return (-1);
		}
		ft_lstpush_back(*lines, current_el);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
