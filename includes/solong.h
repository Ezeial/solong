#ifndef SOLONG_H
# define SOLONG_H

# include "key_linux.h"
# include "libft.h"
# include <mlx.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>  

# define TILE_WIDTH 32
# define TILE_HEIGHT 32

typedef struct	s_img_data {
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img_data;

typedef struct s_map_data {
	size_t		width;
	size_t		height;
	char		**map;
}				t_map_data;

typedef struct	s_win_data {
	void		*mlx;
	void		*win;
	t_img_data	winbuffer;
}				t_win_data;

typedef struct	s_assets {
	t_img_data	player;
	t_img_data	empty;
	t_img_data	exit;
	t_img_data	collectible;
	t_img_data	wall;
}				t_assets;

typedef struct	s_player {
	size_t		x;
	size_t		y;
	size_t		mov;
}				t_player;

typedef struct s_instance
{
	t_map_data	map_data;
	t_win_data	win_data;
	t_assets	assets;
	t_player	player;
}				t_instance;

typedef enum {
	EMPTY = '0',
	WALL = '1',
	EXIT = 'E',
	PLAYER = 'P',
	COLLECTIBLE = 'C'
}				e_map_char;

typedef unsigned char t_byte;

int		*get_pixel_on_img(t_img_data *img_data, int x, int y);
void	put_img_to_buffer(t_img_data *img, t_img_data *buffer, int x, int y);
void	put_pixel_to_img(t_img_data *img, int x, int y, int color);

int		ft_check_format(char *path);
int		ft_read_map(char *path, t_list **lines);
int		ft_check_map(t_list *lines);
int		ft_init_map_data(t_list *lines, t_map_data *map_data);
int		ft_parse(int ac, char **av, t_map_data *map_data);

void	ft_destroy_map_data(t_map_data *map_data);
void	ft_destroy_win_data(t_win_data *win_data);
void	ft_destroy_assets(t_instance *instance);

int		ft_init_win_data(t_win_data *win_data, int size_x, int size_y);
void	ft_load_assets(t_instance *instance);
void 	ft_init_player(t_player *player, t_map_data *map_data);
int		ft_init();

void	ft_draw_player(t_instance *instance);
void	ft_draw_board(t_instance *instance);
void	ft_hook_loop(t_instance *instance);

int		ft_exit_program(t_instance *instance);
void 	ft_on_key_escape(int keycode, t_instance *instance);
void 	ft_on_player_movement(int keycode, t_instance *instance);
void	ft_hook_events(t_instance *instance);

#endif