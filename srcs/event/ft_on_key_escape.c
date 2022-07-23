/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_on_key_escape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egiraldi <egiraldi@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:11:11 by egiraldi          #+#    #+#             */
/*   Updated: 2022/07/23 14:11:18 by egiraldi         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	ft_on_key_escape(int keycode, t_instance *instance)
{
	if (keycode != K_ESC)
		return ;
	ft_exit_program(instance);
}
