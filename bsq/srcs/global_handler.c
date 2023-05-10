/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   global_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:45:36 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 10:24:39 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	global_init(void)
{
	g_map = 0;
	g_mapint = 0;
	g_mapinfo.y = -1;
	g_mapinfo.x = -1;
	g_mapinfo.empty = 0;
	g_mapinfo.obstacle = 0;
	g_mapinfo.full = 0;
}

void	g_map_free_all(int row)
{
	int	idx;

	idx = 0;
	while (idx < row)
	{
		free(g_map[idx]);
		idx++;
	}
	free(g_map);
}

void	g_mapint_free_all(int row)
{
	int	idx;

	idx = 0;
	while (idx < row)
	{
		free(g_mapint[idx]);
		idx++;
	}
	free(g_mapint);
}

void	null_guard(int is_mapint, int row)
{
	if (is_mapint)
	{
		if (g_mapint == 0)
		{
			g_map_free_all(g_mapinfo.y);
			exit(1);
		}
		if (row != -1 && g_mapint[row] == 0)
		{
			g_map_free_all(g_mapinfo.y);
			g_mapint_free_all(row);
			exit(1);
		}
	}
	else
	{
		if (g_map == 0)
			exit(1);
		if (row != -1 && g_map[row] == 0)
		{
			g_map_free_all(row);
			exit(1);
		}
	}
}
