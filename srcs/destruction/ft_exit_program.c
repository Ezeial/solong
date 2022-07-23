/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:10:42 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:10:46 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	ft_exit_program(t_instance *instance)
{
	ft_destroy_assets(instance);
	ft_destroy_win_data(&(instance->win_data));
	ft_destroy_map_data(&(instance->map_data));
	exit(0);
}
