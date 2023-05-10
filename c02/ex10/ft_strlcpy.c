/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 10:05:06 by sryou             #+#    #+#             */
/*   Updated: 2022/02/07 18:33:54 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	len;

	len = ft_strlen(src);
	if (size == 0)
		return (len);
	idx = 0;
	while (*src != '\0' && idx + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		idx++;
	}
	*dest = '\0';
	return (len);
}
