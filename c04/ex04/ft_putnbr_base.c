/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:48:13 by sryou             #+#    #+#             */
/*   Updated: 2022/02/10 08:50:45 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	is_invalid(char *base)
{
	int	idx;

	if (ft_strlen(base) <= 1)
		return (1);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (1);
		idx = 1;
		while (base[idx])
		{
			if (*base == base[idx])
				return (1);
			idx++;
		}
		base++;
	}
	return (0);
}

void	write_nbr_base(int nbr, char *base, int len)
{
	if (nbr == 0)
		return ;
	write_nbr_base(nbr / len, base, len);
	write(1, base + (nbr % len), 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	if (is_invalid(base))
		return ;
	len = ft_strlen(base);
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr == -2147483648)
		{
			write_nbr_base(-(nbr / len), base, len);
			write_nbr_base(-(nbr % len), base, len);
		}
		else
			write_nbr_base(-nbr, base, len);
	}
	else if (nbr == 0)
		write(1, base, 1);
	else
		write_nbr_base(nbr, base, len);
}
