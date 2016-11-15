/*
** ft_putlnbr.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:40:38 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:40:42 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

void	ft_putlnbr(long int n)
{
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
	if (n > 9)
	{
		ft_putlnbr(n / 10);
		ft_putlnbr(n % 10);
	}
	else
		ft_putchar(n + 48);
}
