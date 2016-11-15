/*
** ft_strnew.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:39:33 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:39:34 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (void *)ft_memalloc(size + 1);
	if (new == NULL)
		return ((char *)NULL);
	ft_bzero(new, size + 1);
	return (new);
}
