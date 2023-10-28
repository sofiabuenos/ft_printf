/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:05:05 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/10/28 16:32:54 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putptr(unsigned long ptr, int *count, char *str)
{
	while (ptr >= 16)
	{
		ft_putptr(ptr / 16, count, str);
		ptr = ptr % 16;
	}
	*count += write (1, &str[ptr], 1);
}
