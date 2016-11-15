CC =		gcc

NAME	=		my_stl

LDFLAGS=-lSDL -lSDL_gfx -lSDL_image -lSDL_ttf -lpthread -lwebsockets

SRC	=	main.c \
			init.c \
			pick_color.c \
			display_text.c \
			make_button.c \
			make_text.c \
			make_picture.c \
			make_progress.c \
			set_fullscreen.c \
			handle_click.c \
			start_game.c \
			my_ftl/air_shed.c \
			my_ftl/container.c \
			my_ftl/system_control.c \
			my_ftl/system_repair.c \
			my_ftl/readline.c \
			my_ftl/my_string.c \
			my_ftl/create_ship.c \
			my_ftl/lose_game.c \
			my_ftl/win_game.c \
			my_ftl/display_stats.c \
			my_ftl/calculate_ennemy_states.c \
			my_ftl/get_random_bonus.c \
			my_ftl/launch_detection.c \
			my_ftl/attack.c \
			my_ftl/ship_breakdown.c \
			my_ftl/ennemy_attack.c \
			my_ftl/jump.c \
			my_ftl/check_win.c \
			my_ftl/launch_game.c \
			my_ftl/bonus.c \
			websocket/wss_client.c

SRCS =                  my_ftl/my_printf/libft/ft_chr/ft_chrcat.c \
                        my_ftl/my_printf/libft/ft_chr/ft_chrjoin.c \
                        my_ftl/my_printf/libft/ft_x/ft_itoa.c \
                        my_ftl/my_printf/libft/ft_x/ft_ltoa.c \
                        my_ftl/my_printf/libft/ft_mem/ft_memalloc.c \
                        my_ftl/my_printf/libft/ft_nbr/ft_nbr_base.c \
                        my_ftl/my_printf/libft/ft_put/ft_putchar.c \
                        my_ftl/my_printf/libft/ft_put/ft_putendl.c \
                        my_ftl/my_printf/libft/ft_put/ft_putlnbr.c \
                        my_ftl/my_printf/libft/ft_put/ft_putstr.c \
                        my_ftl/my_printf/libft/ft_str/ft_strcpy.c \
                        my_ftl/my_printf/libft/ft_str/ft_strjoin.c \
                        my_ftl/my_printf/libft/ft_str/ft_strlen.c \
                        my_ftl/my_printf/libft/ft_str/ft_strnew.c \
                        my_ftl/my_printf/libft/ft_str/ft_bzero.c \
                        my_ftl/my_printf/printf_get_base.c \
                        my_ftl/my_printf/printf_get_array.c \
                        my_ftl/my_printf/printf_verify.c \
                        my_ftl/my_printf/my_printf.c \



OBJ	=	$(SRC:%.c=%.o)  $(SRCS:.c=.o)

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all:		$(NAME)

clean:
		$(RM) $(OBJ) $(NAME)

fclean:		clean
		$(RM) $(NAME)

run:		$(NAME)
				./${NAME}

re:		fclean all
