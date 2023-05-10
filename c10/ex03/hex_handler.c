/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:01:41 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 19:10:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

char	ft_16_to_hex(unsigned char c)
{
	if (c >= 10)
		return (c - 10 + 'a');
	else
		return (c + '0');
}

void	ft_char_to_hex(unsigned char c)
{
	ft_putchar(ft_16_to_hex(c / 16));
	ft_putchar(ft_16_to_hex(c % 16));
}

void	putorigin(int size)
{
	ft_putstr("  ");
	ft_putchar('|');
	ft_putstr_printable(g_buf, size);
	ft_putchar('|');
}

void	puthex(int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{	
		if (g_option && idx % 8 == 0)
			ft_putchar(' ');
		ft_putchar(' ');
		ft_char_to_hex(g_buf[idx]);
		idx++;
	}
	while (idx < 16)
	{
		if (g_option && idx % 8 == 0)
			ft_putchar(' ');
		ft_putchar(' ');
		ft_putstr("  ");
		idx++;
	}
	if (g_option)
		putorigin(size);
	ft_putchar('\n');
}

void	putmemory(int size, int count)
{
	unsigned long long	memlong;
	int					idx;
	char				memstr[8];
	int					len;

	memlong = (unsigned long long)count * 16 + size;
	idx = 0;
	len = 7;
	if (g_option)
		len = 8;
	while (idx < len)
	{
		memstr[len - 1 - idx] = ft_16_to_hex(memlong % 16);
		memlong /= 16;
		idx++;
	}
	ft_putnstr(memstr, len);
}
