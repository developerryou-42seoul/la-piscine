/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:11:16 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 16:20:08 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

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

void	ft_putstr_bytes_err(char *filename)
{
	ft_putstr(g_path);
	ft_putstr(": illegal offset -- ");
	ft_putstr(filename);
	ft_putchar('\n');
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
