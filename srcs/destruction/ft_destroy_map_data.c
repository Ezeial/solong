#include "solong.h"

void	ft_destroy_map_data(t_map_data *map_data)
{
	size_t	y;

	if (!map_data->map)
		return ;
	y = 0;
	while (y < map_data->height)
	{
		free(map_data->map[y]);
		y++;
	}
	free(map_data->map);
	map_data->map = NULL;
}