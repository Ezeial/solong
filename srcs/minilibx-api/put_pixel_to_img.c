#include "solong.h"

void put_pixel_to_img(t_img_data *img, int x, int y, int color)
{
	if (( x < 0 || img->width < x ) || ( y < 0 || img->height < y ) || (unsigned int)color == 0xff000000)
		return ;
	*get_pixel_on_img(img, x, y) = color;
}