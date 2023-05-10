/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:25:25 by sryou             #+#    #+#             */
/*   Updated: 2022/02/07 19:03:29 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_printable(char c)
{
	if (' ' <= c && c <= '~')
	{
		return (1);
	}
	return (0);
}

void	putstr_hex(unsigned char c)
{
	char	hexa[3];
	char	*hexarr;

	hexarr = "0123456789abcdef";
	hexa[0] = '\\';
	hexa[1] = hexarr[c / 16];
	hexa[2] = hexarr[c % 16];
	write(1, hexa, 3);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != '\0')
	{
		if (is_printable(*str))
			write(1, str, 1);
		else
			putstr_hex((unsigned char)(*str));
		str++;
	}
}
