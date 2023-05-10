/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:24:16 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 10:25:47 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# define STDINPUT "stdinput_file"

# include "stack.h"
# include "string.h"

void	stdinput_handler(void);
void	file_handler(int argc, char **argv);
void	ft_solve_file(char *argv);
int		is_invalid_file(char *argv);

void	solve(int fd);
void	make_map(int fd);
void	make_mapint(void);
void	make_map_answer(int y, int x, int line);
void	print_map(void);

void	global_init(void);
void	g_map_free_all(int index);
void	g_mapint_free_all(int index);
void	null_guard(int is_mapint, int row);

typedef struct s_mapinfo
{
	int		y;
	int		x;
	char	empty;
	char	obstacle;
	char	full;
}	t_mapinfo;

char		**g_map;
int			**g_mapint;
t_mapinfo	g_mapinfo;

#endif
