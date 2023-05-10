/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:29:04 by sryou             #+#    #+#             */
/*   Updated: 2022/02/14 11:43:42 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
		idx++;
	return (idx);
}

void	ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = 0;
}

struct s_stock_str	_init_stock_str(char *mystring)
{
	t_stock_str	mystock;

	mystock.size = ft_strlen(mystring);
	mystock.str = mystring;
	mystock.copy = (char *)malloc(sizeof(char) * (mystock.size + 1));
	if (mystock.copy != 0)
		ft_strcpy(mystock.copy, mystring);
	return (mystock);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			idx;
	t_stock_str	*mkarr;

	mkarr = 0;
	mkarr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (mkarr == 0)
		return (0);
	idx = 0;
	while (idx < ac)
	{
		mkarr[idx] = _init_stock_str(av[idx]);
		if (mkarr[idx].copy == 0)
		{
			while (--idx >= 0)
				free(mkarr[idx].copy);
			return (0);
		}
		idx++;
	}
	mkarr[idx].size = 0;
	mkarr[idx].str = 0;
	mkarr[idx].copy = 0;
	return (mkarr);
}
