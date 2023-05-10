/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 17:58:11 by sryou             #+#    #+#             */
/*   Updated: 2022/02/14 09:04:40 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

void	ft_strcpy(char *dest, char *str)
{
	while (*str)
	{
		*dest = *str;
		dest++;
		str++;
	}
	*dest = '\0';
}

char	*ft_strdup(char *src)
{
	char	*mkstr;
	int		len;

	len = ft_strlen(src);
	mkstr = (char *)malloc(sizeof(char) * (len + 1));
	if (mkstr == 0)
		return (0);
	ft_strcpy(mkstr, src);
	return (mkstr);
}
