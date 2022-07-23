#include "solong.h"

int	*get_pixel_on_img(t_img_data *img_data, int x, int y)
{
	char	*dst;

	dst = img_data->addr + (y * img_data->line_length + x
			* (img_data->bits_per_pixel / 8));
	return ((int *)dst);
}