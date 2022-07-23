#include "solong.h"

int main(int ac, char **av)
{
	t_instance	instance;
	
	if (ft_parse(ac, av, &(instance.map_data)) < 0)
	{
		printf("Error\nParsing failed\n");
		return (1);
	}
	if (ft_init(&instance) < 0)	
	{
		printf("Error\nInitialization failed\n");
		return (1);
	}
	ft_hook_events(&instance);	
	ft_hook_loop(&instance);
	mlx_loop(instance.win_data.mlx);
	return (0);
}