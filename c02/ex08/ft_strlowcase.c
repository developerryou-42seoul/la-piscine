/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:17:31 by sryou             #+#    #+#             */
/*   Updated: 2022/02/05 10:04:35 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	char	*st_address;

	st_address = str;
	while (*st_address != '\0')
	{
		if ('A' <= *st_address && *st_address <= 'Z')
		{
			*st_address = *st_address + 32;
		}
		st_address++;
	}
	return (str);
}
