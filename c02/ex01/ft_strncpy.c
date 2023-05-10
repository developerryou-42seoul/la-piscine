/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:54:06 by sryou             #+#    #+#             */
/*   Updated: 2022/02/05 08:41:47 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int		idx;
	char				*st_address;

	idx = 0;
	st_address = dest;
	while (idx < n && *src != '\0')
	{
		*st_address = *src;
		st_address++;
		src++;
		idx++;
	}
	while (idx < n)
	{
		*st_address = '\0';
		st_address++;
		idx++;
	}
	return (dest);
}
