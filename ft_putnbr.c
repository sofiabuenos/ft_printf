/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbueno-s <sbueno-s@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:25:14 by sbueno-s          #+#    #+#             */
/*   Updated: 2023/10/28 15:46:18 by sbueno-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int nb, int *count)
{
	unsigned int	nbr;

	nbr = nb;

	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nb;
	}
	while (nbr >= 10)
	{
		ft_putnbr(nbr / 10, count);
		nbr = nbr % 10;
	}
	ft_putchar(nbr + '0', count);
}