/*
** ft_chrjoin.c for  in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:41:25 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:41:26 2015 CHARLES Gracia Jean-Manno
*/

#include "../libft.h"

char	*ft_chrjoin(char const *s1, char s2)
{
	char		*tmp;
	size_t		l1;

	if (s1 == NULL || s2 == 0)
		return (NULL);
	l1 = ft_strlen(s1);
	tmp = ft_memalloc(l1 + 2);
	if (tmp != NULL)
	{
		ft_strcpy(tmp, s1);
		tmp[l1] = s2;
		tmp[l1 + 1] = '\0';
		return (tmp);
	}
	return (NULL);
}
