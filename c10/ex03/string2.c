/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 18:04:32 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 18:08:43 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hexdump.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strncpy(char *dest, char *src, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		*dest = *src;
		idx++;
		dest++;
		src++;
	}
}

int	ft_strncmp(char *str1, char *str2, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		idx++;
	}
	return (0);
}

void	ft_initstr(char *str, int size)
{
	int	idx;

	idx = 0;
	while (idx < size)
	{
		str[idx] = 0;
		idx++;
	}
}
