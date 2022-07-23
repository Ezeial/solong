#include "solong.h"

void ft_on_key_escape(int keycode, t_instance *instance)
{
	if (keycode != K_ESC)
		return ;
	ft_exit_program(instance);
}