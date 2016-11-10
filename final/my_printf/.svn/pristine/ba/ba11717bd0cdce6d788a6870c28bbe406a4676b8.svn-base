/*
** my_printf.c for my_printf in /Users/student/Documents/boehm_e
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:25:15 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:25:16 2015 CHARLES Gracia Jean-Manno
*/

#include "lib_printf.h"

int			my_printf(const char *print, ...)
{
	va_list		ap;
	int			i;
	char		*str;
	char		*output;

	i = 0;
	if (!print)
		return(1);
	va_start(ap, print);
	str = (char *)print;
	output = ft_strnew(ft_strlen(str));
	while(str[i] != '\0')
	{
		verif_replace(&output, str, &i, '%', &ap);
		i++;
	}
	va_end(ap);
	ft_putstr(output);
	return(0);
}
