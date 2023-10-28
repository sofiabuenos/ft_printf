
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
/*function prototypes*/

int		ft_printf(const char *format, ...);
void	ft_putchar(int c, int *count);
void	ft_putstr(const char *s, int *count);
void	ft_putptr(unsigned long ptr, int *count, char *str);
void	ft_putnbr(int nb, int *count);
void	ft_putunint(unsigned int nbr, int *count);

#endif