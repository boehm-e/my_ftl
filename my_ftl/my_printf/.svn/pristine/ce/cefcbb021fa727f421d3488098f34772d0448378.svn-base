/*
** ft_ltoa.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:39:12 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:39:14 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

static int		ft_n_count(long int n, int i)
{
	while (n > 9 || n < 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char			*ft_ltoa(long int n)
{
	int		len;
	long int		nbr;
	char	*str2;
	int		i;
	char	*str;

	len = (n < 0) ? 2 : 1;
	nbr = n;
	i = ft_n_count(n, len);
	str2 = ft_strnew(i + 1);
	while (i > 0)
	{
		if (n >= 0)
			str2[i - 1] = ((char)((nbr % 10) + 48));
		if (n < 0 && i >= 2)
			str2[i - 2] = ((char)(48 - (nbr % 10)));
		i--;
		nbr /= 10;
	}
	if (n < 0)
		str2[i] = '-';
	str = ft_strnew(ft_n_count(n, len) + 1);
	ft_strcpy(str, str2);
	free(str2);
	return (str);
}
