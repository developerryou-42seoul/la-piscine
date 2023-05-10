/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:39:53 by sryou             #+#    #+#             */
/*   Updated: 2022/02/06 11:39:59 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*idx_address;

	idx_address = dest;
	while (*idx_address != '\0')
	{
		idx_address++;
	}
	while (*src != '\0')
	{
		*idx_address = *src;
		idx_address++;
		src++;
	}
	*idx_address = '\0';
	return (dest);
}
