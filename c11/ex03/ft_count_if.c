/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:07:30 by sryou             #+#    #+#             */
/*   Updated: 2022/02/15 19:18:24 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	idx;
	int	count;

	idx = 0;
	count = 0;
	while (idx < length)
	{
		if (f(tab[idx]) != 0)
			count++;
		idx++;
	}
	return (count);
}
