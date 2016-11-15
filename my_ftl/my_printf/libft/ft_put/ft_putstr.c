/*
** ft_putstr.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:40:21 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:40:22 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

void	ft_putstr(char const *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
}
