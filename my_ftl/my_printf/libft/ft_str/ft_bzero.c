/*
** ft_bzero.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:40:06 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:40:07 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

void	ft_bzero(void *s, size_t n)
{
	char		*tmp;

	tmp = (char *)s;
	while (n--)
		tmp[n] = '\0';
}
