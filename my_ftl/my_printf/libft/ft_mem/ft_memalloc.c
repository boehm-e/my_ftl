/*
** ft_memalloc.c for  in /Users/student/Documents/boehm_e/libft
**
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
**
** Started on  Fri Mar  6 18:41:17 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:41:17 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*ptr;

	if ((ptr = malloc(sizeof(*ptr)*size)) != NULL)
		return (ptr);
	else
		return (0);
}
