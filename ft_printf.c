/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:22:09 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/10/28 16:37:49 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/* void ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
} */
static void	ft_arg_type(va_list args,const char *c, int *count)
{
	char *str[2];
	str[0] = "0123456789abcdef";
	str[1] = "0123456789ABCDEF";
	if (*c == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (*c == 's')
		ft_putstr(va_arg(args, const char *), count);
	else if (*c == 'p')
	{
		write(1, "0x", 2);
		*count += 2;
		ft_putptr(va_arg(args, unsigned long), count, str[0]);
	}
	else if (*c == 'd' || *c == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (*c == 'u')
		ft_putunint(va_arg(args, unsigned int), count);
	else if (*c == 'x')
		ft_putptr((unsigned long)va_arg(args, int), count, str[0]);
	else if (*c == 'X')
		ft_putptr((unsigned long)va_arg(args, int), count, str[1]);
	else if (*c == '%')
		ft_putchar('%', count);
}
int	ft_printf(const char *format, ...)
{
	int	count;
	va_list	args;
	
	va_start(args, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_arg_type(args, format, &count);
		}
		else
		{
		count += write(1, format, 1);
		}
		format++;
	}
	va_end(args);
	return (count);
}
int main(void)
{
	int a = 236;
	void *ptr;
	ptr = &a;
	int i;
	int j;
	i = ft_printf("%X\n", a);
	j = printf("%X\n", a);
	printf("%i\n", i);
	printf("%i\n", j);
	return (0);
}