/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:47:44 by sryou             #+#    #+#             */
/*   Updated: 2022/02/20 17:03:04 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

void	read_input_zero(void)
{
	char	*buf;
	int		readn;

	buf = (char *)malloc(sizeof(char));
	if (buf == 0)
		return ;
	readn = 1;
	while (1)
	{
		readn = read(0, buf, 1);
		if (readn <= 0)
			break ;
	}
	free(buf);
}

void	read_input(int tail_bytes)
{
	char	*buf;
	int		idx;

	if (tail_bytes == 0)
	{
		read_input_zero();
		return ;
	}
	buf = (char *)malloc(sizeof(char) * tail_bytes);
	if (buf == 0)
		return ;
	idx = read_buf(buf, 0, tail_bytes);
	write_buf(buf, idx, tail_bytes);
	free(buf);
}

void	read_file(int argc, char **argv, int tail_bytes)
{
	int	idx;
	int	fd;

	idx = 3;
	while (idx < argc)
	{
		g_is_cycled = 0;
		fd = open(argv[idx], O_RDONLY);
		if (fd < 0)
			ft_putstr_err(argv[idx], strerror(errno));
		else
		{
			if (argc > 4)
				write_filename(argv[idx]);
			write_file(fd, tail_bytes);
			close(fd);
		}
		idx++;
	}
}

int	is_wrong_bytes(char *bytes_str)
{
	int	idx;

	idx = 0;
	while (bytes_str[idx])
	{
		if (!('0' <= bytes_str[idx] && bytes_str[idx] <= '9'))
		{
			ft_putstr_bytes_err(bytes_str);
			return (1);
		}
		idx++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	tail_bytes;

	g_path = basename(argv[0]);
	g_is_printed = 0;
	g_is_cycled = 0;
	if (argc >= 3)
	{
		if (is_wrong_bytes(argv[2]))
			return (0);
		tail_bytes = parse_bytes(argv[2]);
		if (argc == 3)
			read_input(tail_bytes);
		else
			read_file(argc, argv, tail_bytes);
	}
	return (0);
}
