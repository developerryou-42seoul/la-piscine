/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:46:00 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 17:20:16 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	write_buf(int size, int count)
{
	if (ft_strncmp(g_container, g_buf, 16) == 0 && !g_is_first)
	{
		if (!g_is_samestr)
			ft_putstr("*\n");
		g_is_samestr = 1;
	}
	else
	{
		putmemory(0, count);
		puthex(size);
		g_is_samestr = 0;
		ft_strncpy(g_container, g_buf, 16);
		ft_initstr(g_buf, 16);
	}
}

void	write_buf_end(int idx, int count)
{
	if (idx != 0)
		write_buf(idx, count);
	if (!g_is_first)
	{
		putmemory(idx, count);
		ft_putchar('\n');
	}
}

unsigned long long	read_buf(int fd, unsigned long long idx_buf, int is_end)
{
	int	count;
	int	idx;
	int	readn;

	count = idx_buf / 16;
	idx = idx_buf % 16;
	while (1)
	{
		readn = read(fd, g_buf + idx, 1);
		if (readn <= 0)
			break ;
		if (idx == 15)
			write_buf(16, count);
		g_is_first = 0;
		idx = (idx + 1) % 16;
		if (idx == 0)
			count++;
		idx_buf++;
	}
	if (is_end)
		write_buf_end(idx, count);
	return (idx_buf);
}

unsigned long long	handle_buf(int fd, unsigned long long idx_buf, int is_end)
{	
	return (read_buf(fd, idx_buf, is_end));
}
