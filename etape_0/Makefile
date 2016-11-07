CC =		gcc

NAME	=		my_ftl

SRC	=	my_ftl.c
OBJ	=	$(SRC:%.c=%.o)

RM	=	rm -f

$(NAME):	$(OBJ)
		$(CC) -o $(NAME) $(OBJ)

all:		$(NAME)


clean:
		$(RM) $(OBJ) $(NAME)

fclean:		clean
		$(RM) $(NAME)

run: 		$(NAME)
				./${NAME}

re:		fclean all
