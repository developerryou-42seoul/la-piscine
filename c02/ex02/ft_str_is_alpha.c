/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:27:41 by sryou             #+#    #+#             */
/*   Updated: 2022/02/05 08:52:02 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != '\0')
	{
		if (!(('A' <= *str && *str <= 'Z') || ('a' <= *str && *str <= 'z')))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
