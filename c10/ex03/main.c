/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:47:44 by sryou             #+#    #+#             */
/*   Updated: 2022/02/20 17:53:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

void	read_input(void)
{
	handle_buf(0, 0, 1);
}

void	read_file(int argc, char **argv)
{
	int					idx;
	int					fd;
	unsigned long long	idx_buf;
	int					is_open;

	idx = 1 + g_option;
	idx_buf = 0;
	is_open = 0;
	while (idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		if (errno > 0)
			ft_putstr_err(argv[idx], strerror(errno));
		else
			is_open = 1;
		errno = 0;
		idx_buf = handle_buf(fd, idx_buf, idx == argc - 1);
		close(fd);
		if (errno > 0 && !is_open && idx == argc - 1)
			ft_putstr_err(argv[idx], strerror(errno));
		errno = 0;
		idx++;
	}
}

int	main(int argc, char **argv)
{
	g_path = basename(argv[0]);
	g_option = 0;
	g_is_first = 1;
	g_is_samestr = 0;
	ft_initstr(g_buf, 16);
	ft_initstr(g_container, 16);
	if (argc == 1)
		read_input();
	else if (argc == 2)
	{
		if (is_option(argv[1]))
			read_input();
		else
			read_file(argc, argv);
	}
	else
	{
		if (is_option(argv[1]))
			read_file(argc, argv);
		else
			read_file(argc, argv);
	}
	return (0);
}
