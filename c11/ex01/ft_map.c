/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:01:56 by sryou             #+#    #+#             */
/*   Updated: 2022/02/15 09:40:14 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	*map;
	int	idx;

	map = (int *)malloc(sizeof(int) * length);
	if (map == 0)
		return (0);
	idx = 0;
	while (idx < length)
	{
		map[idx] = f(tab[idx]);
		idx++;
	}
	return (map);
}
