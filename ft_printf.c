/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 14:22:09 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/10/25 16:08:02 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_putchar(int c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}
void	ft_arg_type(va_list args,const char *c, int *count)
{
	if (*c == 'c')
		ft_putchar(va_arg(args, int), count);	
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
			ft_arg_type(args, format, &count);//verificar qual 'e o tipo do argumento passado e escrever.
		}
		else
		{
		count += write(1, format, 1);
		}
		format++;
		// verificar se count tbm ta contando as os caracteres dos parametros;
	}
	return (count);
}
int main(void)
{
	int i;
	int j;
	i = ft_printf("lalala%c\n", 'a');
	j = printf("lalala%c\n", 'a');
	printf("%i\n", i);
	printf("%i\n", j);
	return (0);
}