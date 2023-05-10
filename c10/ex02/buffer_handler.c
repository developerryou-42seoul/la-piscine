/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:46:00 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 16:42:11 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	init_buf(char *buf, int tail_bytes)
{
	int	idx;

	idx = 0;
	while (idx < tail_bytes)
	{
		buf[idx] = 0;
		idx++;
	}
}

int	read_buf(char *buf, int fd, int tail_bytes)
{
	int	idx;
	int	readn;

	idx = 0;
	init_buf(buf, tail_bytes);
	while (1)
	{
		readn = read(fd, buf + idx, 1);
		if (readn <= 0)
			break ;
		idx = (idx + 1) % tail_bytes;
		if (idx == 0)
			g_is_cycled = 1;
	}
	return (idx);
}

void	write_buf(char *buf, int idx, int tail_bytes)
{
	int	write_idx;

	if (g_is_cycled == 0)
	{
		write_idx = 0;
		while (write_idx < idx)
		{
			ft_putchar(buf[write_idx]);
			write_idx++;
		}
		return ;
	}
	ft_putchar(buf[idx]);
	write_idx = (idx + 1) % tail_bytes;
	while (write_idx != idx)
	{
		ft_putchar(buf[write_idx]);
		write_idx = (write_idx + 1) % tail_bytes;
	}
}
