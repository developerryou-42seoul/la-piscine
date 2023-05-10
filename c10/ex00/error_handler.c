/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:11:08 by sryou             #+#    #+#             */
/*   Updated: 2022/02/14 12:08:52 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display_file.h"

int	print_error(int type)
{
	if (type == 1)
		write(2, "File name missing.\n", 19);
	else if (type == 2)
		write(2, "Too many arguments.\n", 20);
	else if (type == 3)
		write(2, "Cannot read file.\n", 18);
	return (1);
}

int	is_wrong_argc(int argc)
{
	if (argc == 1)
		return (print_error(1));
	if (argc > 2)
		return (print_error(2));
	return (0);
}

int	is_wrong_file(int fd)
{
	if (fd < 0)
		return (print_error(3));
	return (0);
}
