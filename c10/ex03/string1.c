/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:11:16 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 18:08:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_putnstr(char *str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		ft_putchar(str[idx]);
		idx++;
	}
}

void	ft_putstr_printable(char *str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (' ' <= str[idx] && str[idx] <= '~')
			ft_putchar(str[idx]);
		else
			ft_putchar('.');
		idx++;
	}
}

void	ft_putstr_err(char *filename, char *str)
{
	ft_putstr(g_path);
	ft_putstr(": ");
	ft_putstr(filename);
	ft_putstr(": ");
	ft_putstr(str);
	ft_putchar('\n');
}
