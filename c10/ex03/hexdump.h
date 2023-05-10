/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexdump.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:55:54 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 17:10:54 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEXDUMP_H
# define HEXDUMP_H

# include <unistd.h>
# include <stdlib.h>
# include <libgen.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "my_string.h"

int					is_option(char *str);
unsigned long long	handle_buf(int fd, unsigned long long idx_buf, int is_end);

char	*g_path;
int		g_option;
int		g_is_first;
int		g_is_samestr;
char	g_buf[16];
char	g_container[16];

#endif
