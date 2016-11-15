/*
** ft_chrcat.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:41:31 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:41:32 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

char	*ft_chrcat(char *dst, int src)
{
	size_t		ld;

	ld = ft_strlen((const char *)dst);
	dst[ld] = (char)src;
	dst[ld + 1] = '\0';
	return (dst);
}
