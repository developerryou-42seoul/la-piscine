/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 21:47:44 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 15:17:20 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	main(int argc, char **argv)
{
	int		fd;
	int		readn;
	char	*filename;
	char	buf[100];

	if (is_wrong_argc(argc))
		return (1);
	filename = argv[1];
	fd = open(filename, O_RDONLY);
	if (is_wrong_file(fd))
		return (1);
	while (1)
	{
		readn = read(fd, buf, 100);
		if (readn <= 0)
			break ;
		write(1, buf, readn);
	}
	close(fd);
	if (readn < 0)
		return (1);
	return (0);
}
