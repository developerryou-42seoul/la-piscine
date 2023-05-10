/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 11:39:06 by sryou             #+#    #+#             */
/*   Updated: 2022/02/08 20:39:08 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_same(char *str, char *to_find)
{
	while (*to_find != '\0')
	{
		if (*str != *to_find)
			return (0);
		str++;
		to_find++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*str == '\0' && *to_find == '\0')
		return (str);
	while (*str != '\0')
	{
		if (is_same(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
