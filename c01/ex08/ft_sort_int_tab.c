/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:55:51 by sryou             #+#    #+#             */
/*   Updated: 2022/02/03 13:40:49 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	idx_check_value;
	int	idx_search_value;

	idx_check_value = 0;
	while (idx_check_value < size)
	{	
		idx_search_value = idx_check_value + 1;
		while (idx_search_value < size)
		{
			if (tab[idx_check_value] > tab[idx_search_value])
			{
				swap(tab + idx_check_value, tab + idx_search_value);
			}
			idx_search_value++;
		}
		idx_check_value++;
	}
}
