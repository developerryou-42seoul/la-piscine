/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:32:43 by sryou             #+#    #+#             */
/*   Updated: 2022/02/17 13:04:20 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tail.h"

int	ft_strcmp_int(char *str1, char *str2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	if (len1 != len2)
		return (len1 - len2);
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			break ;
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

int	parse_bytes(char *bytes_str)
{
	int	idx;
	int	len;
	int	bytes;

	if (ft_strcmp_int(bytes_str, "2147483647") >= 0)
		return (2147483647);
	len = ft_strlen(bytes_str);
	bytes = 0;
	idx = 0;
	while (idx < len)
	{
		bytes = bytes * 10 + (bytes_str[idx] - '0');
		idx++;
	}
	return (bytes);
}
