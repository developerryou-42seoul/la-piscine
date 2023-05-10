/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:24:40 by sryou             #+#    #+#             */
/*   Updated: 2022/02/16 11:14:56 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	long long	len;
	long long	idx;

	*range = 0;
	len = (long long)max - (long long)min;
	if (len > 0)
	{
		*range = (int *)malloc(sizeof(int) * len);
		if (*range == 0)
			return (-1);
		idx = 0;
		while (idx < len)
		{
			(*range)[idx] = min + idx;
			idx++;
		}
		return ((int)len);
	}
	else
		return (0);
}
