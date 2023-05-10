/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:37:09 by sryou             #+#    #+#             */
/*   Updated: 2022/02/13 08:42:52 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
int		print_error(void);
int		print_map(int **map, int map_size);
int		is_valid_string(char *str);
int		is_valid_map(int **map, int *watch, int map_size);
int		*init_watch(char *str, int size);
int		**init_map(int size);
int		recursive(int **map, int *watch, int idx, int map_size);
int		is_putable(int **map, int idx_y, int idx_x, int value);
int		is_watchable(int **map, int *watch, int idx, int map_size);
int		is_le_dup(int *val1, int val2);

#endif
