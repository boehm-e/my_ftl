/*
** ft_putnbr_base.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:40:30 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:40:31 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

void	ft_putnbr_base(int n, char *str)
{
	int	base;

	base = ft_strlen(str);

	if (n < 0)
	{
		if (n == -2147483648)
		{
			ft_putstr("-2147483648");
			return ;
		}
		else
		{
			ft_putchar('-');
			n = n * -1;
		}
	}
	if (n >= base)
		ft_putnbr_base(n / base, str);
	else
		ft_putchar(str[(n % base)]);
}
