/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:08:23 by sryou             #+#    #+#             */
/*   Updated: 2022/02/03 20:15:44 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strupcase(char *str)
{
	char	*st_address;

	st_address = str;
	while (*st_address != '\0')
	{
		if ('a' <= *st_address && *st_address <= 'z')
		{
			*st_address = *st_address - 32;
		}
		st_address++;
	}
	return (str);
}
