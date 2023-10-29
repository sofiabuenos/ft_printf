/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:05:05 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/10/29 16:16:19 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_puthex(unsigned long ptr, int *count, char *str)
{
	int	len;

	len = ft_strlen(str);
	while (ptr >= (unsigned long)len)
	{
		ft_puthex(ptr / (unsigned long)len, count, str);
		ptr = ptr % (unsigned long)len;
	}
	*count += write (1, &str[ptr], 1);
}
