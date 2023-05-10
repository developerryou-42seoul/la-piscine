/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:41:20 by sryou             #+#    #+#             */
/*   Updated: 2022/02/08 12:41:30 by sryou            ###   ########.fr       */
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

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	idx;
	unsigned int	src_len;
	unsigned int	dest_len;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	if (size == 0)
		return (src_len);
	idx = dest_len;
	dest = dest + dest_len;
	while (*src != '\0' && idx + 1 < size)
	{
		*dest = *src;
		dest++;
		src++;
		idx++;
	}
	*dest = '\0';
	if (dest_len >= size)
		return (size + src_len);
	else
		return (dest_len + src_len);
}
