/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:34:50 by sryou             #+#    #+#             */
/*   Updated: 2022/02/06 11:35:08 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*idx_address;

	idx_address = dest;
	while (*idx_address != '\0')
		idx_address++;
	while (*src != '\0' && nb > 0)
	{
		*idx_address = *src;
		idx_address++;
		src++;
		nb--;
	}
	*idx_address = '\0';
	return (dest);
}
