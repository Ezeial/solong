#include "solong.h"

int	ft_exit_program(t_instance *instance)
{
	ft_destroy_assets(instance);
	ft_destroy_win_data(&(instance->win_data));
	ft_destroy_map_data(&(instance->map_data));
	exit(0);
}