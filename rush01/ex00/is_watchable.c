/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_putable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:24 by dopaek            #+#    #+#             */
/*   Updated: 2022/02/13 08:48:33 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	count_left(int **map, int y, int x)
{
	int	idx_x;
	int	min;
	int	count;

	idx_x = 0;
	min = 0;
	count = 0;
	while (idx_x <= x)
	{
		if (is_le_dup(&min, map[y][idx_x]))
			count++;
		idx_x++;
	}
	return (count);
}

int	count_up(int **map, int y, int x)
{
	int	idx_y;
	int	min;
	int	count;

	idx_y = 0;
	min = 0;
	count = 0;
	while (idx_y <= y)
	{
		if (is_le_dup(&min, map[idx_y][x]))
			count++;
		idx_y++;
	}
	return (count);
}

int	is_watchable(int **map, int *watch, int idx, int map_size)
{
	int	x;
	int	y;

	x = idx % map_size;
	y = idx / map_size;
	if (watch[map_size * 2 + y] < count_left(map, y, x))
		return (0);
	if (watch[x] < count_up(map, y, x))
		return (0);
	return (1);
}
