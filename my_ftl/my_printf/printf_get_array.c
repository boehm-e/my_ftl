/*
** printf_get_array.c for printf_get_array in /Users/student/Documents/boehm_e
**
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
**
** Started on  Fri Mar  6 18:25:32 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:25:33 2015 CHARLES Gracia Jean-Manno
*/

#include "lib_printf.h"

void		get_print_l(va_list *ap, int ***n, char ****op)
{
	long int	tmp_l;
	char	*tmp_s;

	tmp_l = 0;
	tmp_l = va_arg(*ap, long int);
	if (tmp_l == 0)
	{
		ft_putstr("Error printf1!!!\n");
		exit(1);
	}
	tmp_s = ft_ltoa(tmp_l);
	***op = ft_strjoin(***op, tmp_s);
	***n += 2;
}

void		get_print_u(va_list *ap, int ***n, char ****op)
{
	int		tmp_u;
	char	*tmp_c;

	tmp_u = va_arg(*ap, int);
	if (tmp_u == 0)
	{
		ft_putstr("Error printf2!!!\n");
		exit(1);
	}
	tmp_c = ft_nbr_base(tmp_u, "0123456789");
	***op = ft_strjoin(***op, tmp_c);
	***n += 1;
	free(tmp_c);
}

void		get_print_d_i(va_list *ap, int ***n, char ****op)
{
	int		tmp_i;
	char	*tmp_s;

	tmp_i = 0;
	tmp_i = va_arg(*ap, int);
	if (tmp_i == 0)
	{
		ft_putstr("Error printf3!!!\n");
		exit(1);
	}
	tmp_s = ft_itoa(tmp_i);
	***op = ft_strjoin(***op, tmp_s);
	***n += 1;
}

void		get_print_c(va_list *ap, int ***n, char ****op)
{
	char	tmp_c;

	tmp_c = va_arg(*ap, int);
	if (!tmp_c)
	{
		ft_putstr("Error printf4!!!\n");
		exit(1);
	}
	***op = ft_chrjoin(***op, tmp_c);
	***n += 1;
}

void		get_print_s(va_list *ap, int ***n, char ****op)
{
	char 	*tmp_s;

	tmp_s = va_arg(*ap, char *);
	if (!tmp_s)
	{
		ft_putstr("Error printf5!!!\n");
		exit(1);
	}
	***op = ft_strjoin(***op, tmp_s);
	***n += 1;
}
