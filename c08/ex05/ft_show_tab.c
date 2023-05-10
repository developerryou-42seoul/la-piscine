/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:09:46 by sryou             #+#    #+#             */
/*   Updated: 2022/02/14 11:44:19 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rec_putnbr(long long int nbr)
{
	if (nbr == 0)
		return ;
	rec_putnbr(nbr / 10);
	ft_putchar(nbr % 10 + '0');
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		rec_putnbr(-(long long int)nbr);
	}
	else if (nbr == 0)
		ft_putchar('0');
	else
		rec_putnbr((long long int)nbr);
	ft_putchar('\n');
}

void	_ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	idx;

	idx = 0;
	while (par[idx].str != 0)
	{
		_ft_putstr(par[idx].str);
		ft_putnbr(par[idx].size);
		_ft_putstr(par[idx].copy);
		idx++;
	}
}
