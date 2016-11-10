/*
** printf_verify.c for printf_verify in /Users/student/Documents/boehm_e
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:25:57 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:25:58 2015 CHARLES Gracia Jean-Manno
*/

#include "lib_printf.h"

void		check_flags_replace(char *s, int i, char ***op, int **n, va_list *ap)
{
	int index = 0;

	t_flags flags[] = {
		{'s', get_print_s},
		{'c', get_print_c},
		{'i', get_print_d_i},
		{'d', get_print_d_i},
		{'u', get_print_u},
		{'o', get_print_o},
		{'x', get_print_x},
		{'X', get_print_xx},
		{'%', get_print_pc},
		{'l', get_print_l},
		{'\0', NULL}
	};

	while (flags[index].flag != '\0')
	{
		if (s[i] == flags[index].flag)
			flags[index].f(ap, &n, &op);
		index++;
	}
}

void		verif_replace(char **op, char *s, int *i, int c, va_list *ap)
{
	if (s[*i] != (char)c)
		ft_chrcat(*op, s[*i]);
	else if (s[*i] == (char)c)
	  check_flags_replace(s, (*i)+1, &op, &i, ap);
}
