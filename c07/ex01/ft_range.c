/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:12:30 by sryou             #+#    #+#             */
/*   Updated: 2022/02/16 11:14:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int			*mkarr;
	long long	len;
	long long	idx;

	len = (long long)max - (long long)min;
	if (len > 0)
	{
		mkarr = (int *)malloc(sizeof(int) * len);
		if (mkarr == 0)
			return (0);
		idx = 0;
		while (idx < len)
		{
			mkarr[idx] = min + idx;
			idx++;
		}
		return (mkarr);
	}
	return (0);
}
