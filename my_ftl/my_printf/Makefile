##
## Makefile for Makefile in /Users/student/Documents/boehm_e
## 
## Made by CHARLES Gracia Jean-Manno
## Login   <charle_g@etna-alternance.net>
## 
## Started on  Fri Mar  6 18:24:27 2015 CHARLES Gracia Jean-Manno
## Last update Fri Mar  6 18:44:33 2015 CHARLES Gracia Jean-Manno
##

NAME =			a.out

L_PRINTF_DYNM =		libmy_printf_`uname -m`-`uname -s`.so

L_PRINTF_STAT =		libmy_printf_`uname -m`-`uname -s`.a

SRC_L_FT = 		./libft

SRCS =			libft/ft_chr/ft_chrcat.c \
			libft/ft_chr/ft_chrjoin.c \
			libft/ft_x/ft_itoa.c \
			libft/ft_x/ft_ltoa.c \
			libft/ft_mem/ft_memalloc.c \
			libft/ft_nbr/ft_nbr_base.c \
			libft/ft_put/ft_putchar.c \
			libft/ft_put/ft_putendl.c \
			libft/ft_put/ft_putlnbr.c \
			libft/ft_put/ft_putstr.c \
			libft/ft_str/ft_strcpy.c \
			libft/ft_str/ft_strjoin.c \
			libft/ft_str/ft_strlen.c \
			libft/ft_str/ft_strnew.c \
			libft/ft_str/ft_bzero.c \
			printf_get_base.c \
			printf_get_array.c \
			printf_verify.c \
			my_printf.c \
			main.c \

OBJS =			$(SRCS:.c=.o)

GCFLAGS =		gcc -Wall -Wextra -W -Werror

RM =			rm -Rf

all:			$(NAME)

$(NAME):		$(OBJS)
			@ar rc $(L_PRINTF_STAT) $(OBJS)
			@ranlib $(L_PRINTF_STAT)
			@$(GCFLAGS) -shared -o $(L_PRINTF_DYNM) $(OBJS)

my_printf_static:	$(OBJS)
			@ar rc $(L_PRINTF_STAT) $(OBJS)
			@ranlib $(L_PRINTF_STAT)

my_printf_dynamic:	$(OBJS)
			$(GCFLAGS) -shared -o $(L_PRINTF_DYNM) $(OBJS)

clean:
			@$(RM) $(L_PRINTF_DYNM)
			@$(RM) $(L_PRINTF_STAT)
			@$(RM) $(OBJS)
			@$(RM) **/*~
			@$(RM) **/#*#
			@$(RM) *~
			@$(RM) #*#

fclean:			clean
			@$(RM) $(NAME)

re:			fclean all

%.o:			%.c
			@$(GCFLAGS) -c $< -o $@

.PHONY:			all clean fclean re
