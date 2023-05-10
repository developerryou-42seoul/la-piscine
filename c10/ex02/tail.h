/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tail.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:23:46 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 16:16:23 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TAIL_H
# define TAIL_H

# include <unistd.h>
# include <stdlib.h>
# include <libgen.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

int		parse_bytes(char *bytes_str);
void	write_filename(char *filename);
void	write_file(int fd, int tail_bytes);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_bytes_err(char *filename);
void	ft_putstr_err(char *filename, char *str);
int		read_buf(char *buf, int fd, int tail_bytes);
void	write_buf(char *buf, int idx, int tail_bytes);

char	*g_path;
int		g_is_printed;
int		g_is_cycled;

#endif
