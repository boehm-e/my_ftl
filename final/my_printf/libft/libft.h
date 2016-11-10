/*
** libft.h for libft in /Users/student/Documents/boehm_e/libft
** 
** Made by CHARLES Gracia Jean-Manno
** Login   <charle_g@etna-alternance.net>
** 
** Started on  Fri Mar  6 18:24:14 2015 CHARLES Gracia Jean-Manno
** Last update Fri Mar  6 18:24:15 2015 CHARLES Gracia Jean-Manno
*/

#ifndef LIBFT_H_
# define LIBFT_H_

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

char			*ft_chrcat(char *dst, int src);
char			*ft_chrjoin(char const *s1, char s2);
void			*ft_memalloc(size_t size);
char			*ft_nbr_base(int n, char *str);
void			ft_putchar(char c);
void			ft_putendl(char const *s);
void			ft_putlnbr(long int n);
void			ft_putnbr_base(int n, char *str);
void			ft_putstr(char const *s);
void			ft_bzero(void *s, size_t n);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlen(const char *s);
char			*ft_strnew(size_t size);
char			*ft_itoa(int n);
char			*ft_ltoa(long int n);

#endif
