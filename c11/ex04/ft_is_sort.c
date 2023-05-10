/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 09:09:17 by sryou             #+#    #+#             */
/*   Updated: 2022/02/15 19:18:33 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	idx;
	int	acending;
	int	decending;

	idx = 0;
	acending = 1;
	decending = 1;
	while (idx < length - 1)
	{
		if (f(tab[idx], tab[idx + 1]) < 0)
			decending = 0;
		if (f(tab[idx], tab[idx + 1]) > 0)
			acending = 0;
		idx++;
	}
	if (acending || decending)
		return (1);
	return (0);
}
