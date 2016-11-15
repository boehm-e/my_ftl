/*
** ft_nbr_base.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:41:04 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:41:06 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

char	*ft_nbr_base(int n, char *str)
{
	int	base;
	static char	*ret = NULL;
	static int	test = 0;

	ret = ft_strnew(1);
	base = ft_strlen(str);
	if (n < 0)
	{
		n = n * -1;
		test++;
	}
	if (n >= base)
	{
		ft_nbr_base(n / base, str);
	}
	if (test == 1)
	{
		ret = ft_chrjoin(ret, '-');
		test = 0;
	}
	ret = ft_chrjoin(ret, str[(n % base)]);
	return (ret);
}
