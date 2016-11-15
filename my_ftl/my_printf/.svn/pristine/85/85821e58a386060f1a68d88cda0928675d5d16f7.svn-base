/*
** ft_strjoin.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:39:39 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:39:41 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*tmp;
	size_t		l1;
	size_t		l2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	tmp = ft_memalloc(l1 + l2 + 1);
	if (tmp != NULL)
	{
		ft_strcpy(tmp, s1);
		ft_strcpy(tmp + l1, s2);
		return (tmp);
	}
	return (NULL);
}
