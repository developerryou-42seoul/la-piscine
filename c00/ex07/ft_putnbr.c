/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:38:37 by sryou             #+#    #+#             */
/*   Updated: 2022/02/03 10:48:29 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_nega(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb == -2147483648)
		{
			write(1, "2", 1);
			nb = -147483648;
		}
		nb = -nb;
	}
	return (nb);
}

void	ft_putnbr(int nb)
{
	int		div_num;
	int		check;
	char	write_buf;

	nb = check_nega(nb);
	div_num = 1000000000;
	check = 0;
	while (div_num > 0)
	{
		if (nb / div_num > 0)
		{
			check = 1;
		}
		if (check)
		{
			write_buf = nb / div_num + '0';
			write(1, &write_buf, 1);
			nb = nb % div_num;
		}
		div_num /= 10;
	}
	if (check == 0)
	{
		write(1, "0", 1);
	}
}
