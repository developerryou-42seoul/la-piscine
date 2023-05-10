/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 13:06:25 by sryou             #+#    #+#             */
/*   Updated: 2022/02/20 17:03:05 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	write_file_zero(int fd)
{
	char	*buf;
	int		readn;

	buf = (char *)malloc(sizeof(char));
	if (buf == 0)
		return ;
	readn = 1;
	while (1)
	{
		readn = read(fd, buf, 1);
		if (readn <= 0)
			break ;
	}
	free(buf);
}

void	write_file(int fd, int tail_bytes)
{
	char	*buf;
	int		idx;

	if (tail_bytes == 0)
	{
		write_file_zero(fd);
		return ;
	}
	buf = (char *)malloc(sizeof(char) * tail_bytes);
	if (buf == 0)
		return ;
	idx = read_buf(buf, fd, tail_bytes);
	write_buf(buf, idx, tail_bytes);
	free(buf);
}

void	write_filename(char *filename)
{
	if (g_is_printed)
		ft_putchar('\n');
	ft_putstr("==> ");
	ft_putstr(filename);
	ft_putstr(" <==");
	ft_putchar('\n');
	g_is_printed = 1;
}
