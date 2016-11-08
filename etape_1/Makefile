CC =		gcc -g3

CFLAGS +=	-Wall -Werror -Wextra
NAME	=		my_ftl

SRC	=	air_shed.c my_string.c container.c system_control.c system_repair.c
OBJ	=	$(SRC:%.c=%.o)
LDFLAGS	=	-L./libs -lmy -static

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
