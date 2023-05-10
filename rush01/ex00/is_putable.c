/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_putable.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopaek <dopaek@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 10:36:24 by dopaek            #+#    #+#             */
/*   Updated: 2022/02/12 21:15:11 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	is_putable(int **map, int idx_y, int idx_x, int value)
{
	int	x;
	int	y;

	x = idx_x;
	y = idx_y;
	while (--idx_x >= 0)
	{
		if (map[y][idx_x] == value)
			return (0);
	}
	while (--idx_y >= 0)
	{
		if (map[idx_y][x] == value)
			return (0);
	}
	return (1);
}
