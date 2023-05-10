/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hehwang <hehwang@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:28:53 by hehwang           #+#    #+#             */
/*   Updated: 2022/02/13 17:31:29 by hehwang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**init_map(int size)
{
	int	**map;
	int	i;
	int	j;

	map = (int **)malloc(sizeof(int *) * size);
	if (map == 0)
		return (0);
	i = -1;
	while (++i < size)
	{
		map[i] = (int *)malloc(sizeof(int) * size);
		if (map[i] == 0)
		{
			while (--i >= 0)
				free(map[i]);
			free(map);
			return (0);
		}
		j = -1;
		while (++j < size)
			map[i][j] = 0;
	}
	return (map);
}
