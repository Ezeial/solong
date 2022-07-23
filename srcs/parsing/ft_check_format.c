/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:30:32 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:54:03 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_check_format(char *path)
{
	size_t	idx;

	idx = 0;
	while (path[idx])
		idx++;
	if (idx < 6)
		return (-1);
	if (ft_strncmp(&(path[idx - 4]), ".ber", idx))
		return (-1);
	return (0);
}
