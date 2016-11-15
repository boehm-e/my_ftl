/*
** printf_get_base.c for printf_get_base in /Users/student/Documents/boehm_e
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:25:44 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:25:46 2015 CHARLES Gracia Jean-Manno
*/

#include "lib_printf.h"

void		get_print_pc(va_list *ap, int ***n, char ****op)
{
	int 	x;

	x = 0;
	ap ? x++ : x-- ;
	***op = ft_chrjoin(***op, '%');
	***n += 1;
}

void		get_print_xx(va_list *ap, int ***n, char ****op)
{
	int		tmp_xx;
	char	*tmp_c;

	tmp_xx = va_arg(*ap, int);
	if (tmp_xx == 0)
	{
		ft_putstr("Error printf!!!1\n");
		exit(1);
	}
	tmp_c = ft_nbr_base(tmp_xx, "0123456789ABCDEF");
	***op = ft_strjoin(***op, tmp_c);
	***n += 1;
	free(tmp_c);
}

void		get_print_x(va_list *ap, int ***n, char ****op)
{
	int		tmp_x;
	char	*tmp_c;

	tmp_x = va_arg(*ap, int);
	if (tmp_x == 0)
	{
		ft_putstr("Error printf!!!2\n");
		exit(1);
	}
	tmp_c = ft_nbr_base(tmp_x, "0123456789abcdef");
	***op = ft_strjoin(***op, tmp_c);
	***n += 1;
	free(tmp_c);
}

void		get_print_o(va_list *ap, int ***n, char ****op)
{
	int		tmp_o;
	char	*tmp_c;

	tmp_o = va_arg(*ap, int);
	if (tmp_o == 0)
	{
		ft_putstr("Error printf!!!3\n");
		exit(1);
	}
	tmp_c = ft_nbr_base(tmp_o, "01234567");
	***op = ft_strjoin(***op, tmp_c);
	***n += 1;
	free(tmp_c);
}
