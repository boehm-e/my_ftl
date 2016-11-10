/*
** lib_printf.h for lib_printf_h in /Users/student/Documents/boehm_e
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:24:53 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:24:55 2015 CHARLES Gracia Jean-Manno
*/

#ifndef LIB_PRINTF_H_
# define LIB_PRINTF_H_

# include "libft/libft.h"
# include <stdarg.h>

void			get_print_l(va_list *ap, int ***n, char ****op);
void			get_print_pc(va_list *ap, int ***n, char ****op);
void			get_print_xx(va_list *ap, int ***n, char ****op);
void			get_print_x(va_list *ap, int ***n, char ****op);
void			get_print_o(va_list *ap, int ***n, char ****op);
void			get_print_u(va_list *ap, int ***n, char ****op);
void			get_print_d_i(va_list *ap, int ***n, char ****op);
void			get_print_c(va_list *ap, int ***n, char ****op);
void			get_print_s(va_list *ap, int ***n, char ****op);

typedef struct		s_flags
{
			char flag;
			void (*f)(va_list *ap, int ***n, char ****op);
}			t_flags;

void			check_flags_replace(char *s, int i, char ***op, int **n, va_list *ap);
void			verif_replace(char **op, char *s, int *i, int c, va_list *ap);
int			my_printf(const char *print, ...);

#endif
