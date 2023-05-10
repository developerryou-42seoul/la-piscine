/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:54:02 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 08:40:13 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

int	check_nega(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
		nb = -nb;
	}
	return (nb);
}

void	recursive_write(int nb)
{
	if (nb == 0)
		return ;
	recursive_write(nb / 10);
	ft_putchar((nb % 10) + '0');
}

void	ft_putnbr(int nbr)
{
	nbr = check_nega(nbr);
	recursive_write(nbr);
	if (nbr == 0)
		ft_putchar('0');
	ft_putchar('\n');
}
