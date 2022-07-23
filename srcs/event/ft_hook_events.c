#include "solong.h"

static int	ft_keypress(int keycode, t_instance *instance)
{
	ft_on_key_escape(keycode, instance);
	ft_on_player_movement(keycode, instance);
	return (0);
}

void		ft_hook_events(t_instance *instance)
{
	mlx_hook(instance->win_data.win, 17, 1L << 0, ft_exit_program, instance);
	mlx_key_hook(instance->win_data.win, ft_keypress, instance);
}