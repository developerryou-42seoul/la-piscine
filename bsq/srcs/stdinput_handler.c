/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdinput_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:32:51 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 10:12:34 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	stdinput_handler(void)
{
	int		fd;
	int		readn;
	char	buf[100];

	fd = open(STDINPUT, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd < 0)
	{
		ft_puterr();
		return ;
	}
	while (1)
	{
		readn = read(0, buf, 100);
		if (readn <= 0)
			break ;
		write(fd, buf, readn);
	}
	close(fd);
}
