/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:47:44 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 19:01:53 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

void	read_file(int argc, char **argv)
{
	int		idx;
	int		fd;
	int		readn;
	char	buf[100];

	idx = 1;
	while (idx < argc)
	{
		fd = open(argv[idx], O_RDONLY);
		if (fd < 0)
			ft_putstr_err(argv[idx], strerror(errno));
		else
		{
			while (1)
			{
				readn = read(fd, buf, 100);
				if (readn <= 0)
					break ;
				write(1, buf, readn);
			}
			close(fd);
		}
		idx++;
	}
}

void	read_input(void)
{
	int		readn;
	char	buf[100];

	while (1)
	{
		readn = read(0, buf, 100);
		if (readn <= 0)
			break ;
		write(1, buf, readn);
	}
}

int	main(int argc, char **argv)
{
	g_path = basename(argv[0]);
	if (argc == 1)
		read_input();
	else
		read_file(argc, argv);
	return (0);
}
