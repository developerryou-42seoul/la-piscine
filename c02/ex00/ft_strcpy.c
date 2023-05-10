/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:38:50 by sryou             #+#    #+#             */
/*   Updated: 2022/02/05 08:35:38 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char	*idx_address;

	idx_address = dest;
	while (*src != '\0')
	{
		*idx_address = *src;
		idx_address++;
		src++;
	}
	*idx_address = '\0';
	return (dest);
}
