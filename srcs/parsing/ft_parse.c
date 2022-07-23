#include "solong.h"


int	ft_parse(int ac, char **av, t_map_data *map_data)
{
	t_list		*lines;

	if (ac != 2)
		return (-1);
	if (ft_check_format(av[1]) < 0)
		return (-1);
	if (ft_read_map(av[1], &lines) < 0)
		return (-1);
	if (ft_check_map(lines) < 0)
	{
		ft_lstclear(lines, free);
		return (-1);
	}
	ft_init_map_data(lines, map_data);
	ft_lstclear(lines, free);
	return (0);
}

