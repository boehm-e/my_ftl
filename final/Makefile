CC =		gcc -g3

CFLAGS +=	-Wall -Werror -Wextra
NAME	=		my_ftl

SRC	=	air_shed.c \
			container.c \
			system_control.c \
			system_repair.c \
			readline.c \
			my_string.c \
			create_ship.c \
			lose_game.c \
			win_game.c \
			display_stats.c \
			calculate_ennemy_states.c \
			get_random_bonus.c \
			launch_detection.c \
			attack.c \
			ship_breakdown.c \
			ennemy_attack.c \
			jump.c \
			check_win.c \
			launch_game.c \
			bonus.c


SRCS =                  my_printf/libft/ft_chr/ft_chrcat.c \
                        my_printf/libft/ft_chr/ft_chrjoin.c \
                        my_printf/libft/ft_x/ft_itoa.c \
                        my_printf/libft/ft_x/ft_ltoa.c \
                        my_printf/libft/ft_mem/ft_memalloc.c \
                        my_printf/libft/ft_nbr/ft_nbr_base.c \
                        my_printf/libft/ft_put/ft_putchar.c \
                        my_printf/libft/ft_put/ft_putendl.c \
                        my_printf/libft/ft_put/ft_putlnbr.c \
                        my_printf/libft/ft_put/ft_putstr.c \
                        my_printf/libft/ft_str/ft_strcpy.c \
                        my_printf/libft/ft_str/ft_strjoin.c \
                        my_printf/libft/ft_str/ft_strlen.c \
                        my_printf/libft/ft_str/ft_strnew.c \
                        my_printf/libft/ft_str/ft_bzero.c \
                        my_printf/printf_get_base.c \
                        my_printf/printf_get_array.c \
                        my_printf/printf_verify.c \
                        my_printf/my_printf.c \


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
