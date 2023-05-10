/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 08:44:00 by sryou             #+#    #+#             */
/*   Updated: 2022/02/14 11:15:31 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_str_cat_return_end(char *dest, char *str)
{
	while (*str)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = 0;
	return (dest);
}

long long int	ft_str_len(char *str)
{
	long long int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

long long int	ft_str_total_len(int size, char **src, char *sep)
{
	long long int	len_sep;
	long long int	len_src;
	int				idx;

	len_sep = (size - 1) * ft_str_len(sep);
	len_src = 0;
	idx = 0;
	while (idx < size)
	{
		len_src += ft_str_len(src[idx]);
		idx++;
	}
	return (len_src + len_sep);
}

void	ft_str_cats(char *mkstr, int size, char **src, char *sep)
{
	int	idx;

	idx = 0;
	mkstr = ft_str_cat_return_end(mkstr, src[idx]);
	idx++;
	while (idx < size)
	{
		mkstr = ft_str_cat_return_end(mkstr, sep);
		mkstr = ft_str_cat_return_end(mkstr, src[idx]);
		idx++;
	}
}

char	*ft_strjoin(int size, char **src, char *sep)
{
	char				*mkstr;
	long long int		total_len;

	if (size == 0)
	{
		mkstr = (char *)malloc(sizeof(char) * 1);
		mkstr[0] = 0;
		return (mkstr);
	}
	total_len = ft_str_total_len(size, src, sep);
	mkstr = (char *)malloc(sizeof(char) * (total_len + 1));
	if (mkstr == 0)
		return (0);
	ft_str_cats(mkstr, size, src, sep);
	return (mkstr);
}
