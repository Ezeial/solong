#-----------------------------------------------#
#-----------------[ SRCS NAME ]-----------------#
#-----------------------------------------------#

SRCS_FLAT		=	main.c \
					minilibx-api/get_pixel_on_img.c minilibx-api/put_img_to_buffer.c minilibx-api/put_pixel_to_img.c \
					parsing/ft_check_format.c parsing/ft_parse.c parsing/ft_read_map.c parsing/ft_check_map.c parsing/ft_init_map_data.c \
					initialization/ft_init.c initialization/ft_init_win_data.c initialization/ft_load_assets.c initialization/ft_init_player.c \
					loop/ft_draw_board.c loop/ft_draw_player.c loop/ft_hook_loop.c \
					event/ft_hook_events.c event/ft_on_key_escape.c event/ft_on_player_movement.c \
					destruction/ft_destroy_map_data.c destruction/ft_destroy_win_data.c destruction/ft_destroy_assets.c destruction/ft_exit_program.c

SRCS			=	$(addprefix srcs/, $(SRCS_FLAT:.c=.o))

#-----------------------------------------------#
#----------------[ COMPILATION ]----------------#
#-----------------------------------------------#

CC				=	gcc
RM				=	rm -rf
CFLAGS			=	-Wall -Wextra -Werror -fsanitize=address

DIR_INCLUDES	=	includes
HEADERS			=	solong.h
INCLUDES 		=	$(addprefix $(DIR_INCLUDES)/, $(HEADERS))

NAME			=	so_long

OBJS			=	$(SRCS:.c=.o)	

#-----------------------------------------------#
#-------------------[ TARGET ]------------------#
#-----------------------------------------------#

all:			$(NAME)

%.o:			%.c $(INCLUDES)
				$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -I$(DIR_INCLUDES) -Ilibft/includes -O3 -c $< -o $@

$(NAME):		$(OBJS)
				make -C libft
				$(CC) $(CFLAGS) $(OBJS) -L./libft -lft -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
				make clean -C libft
				$(RM) $(OBJS)

fclean:			clean
				make fclean -C libft
				$(RM) $(NAME)

re:				fclean $(NAME)

test:			all clean

.PHONY:			all clean fclean re