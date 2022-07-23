/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:35:42 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:44:08 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_set_flag(t_byte *tiles, char c)
{
	if (c == 'E')
		*tiles |= 0x1;
	if (c == 'P')
		*tiles |= 0x2;
	if (c == 'C')
		*tiles |= 0x4;
}

int	ft_check_side_border(t_list_elem *top, size_t width)
{
	while (top)
	{
		if (((char *)(top->data))[0] != '1' ||
				((char *)(top->data))[width - 1] != '1')
			return (-1);
		top = top->next;
	}
	return (0);
}
