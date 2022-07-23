#include "solong.h"

int	ft_init_win_data(t_win_data *win_data, int size_x, int size_y)
{
	win_data->mlx = mlx_init();
	if (!(win_data->mlx))
		return (-1);
	win_data->win = mlx_new_window(win_data->mlx, size_x, size_y, "so_long");
	win_data->winbuffer.img = mlx_new_image(win_data->mlx, size_x, size_y);
	win_data->winbuffer.addr = mlx_get_data_addr(
		win_data->winbuffer.img,
		&(win_data->winbuffer.bits_per_pixel),
		&(win_data->winbuffer.line_length),
		&(win_data->winbuffer.endian)
	);
	win_data->winbuffer.height = size_y;
	win_data->winbuffer.width = size_x;
	return (0);
}