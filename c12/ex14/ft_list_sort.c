/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:28:33 by sryou             #+#    #+#             */
/*   Updated: 2022/02/19 19:50:10 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	_ft_list_size(t_list *begin_list)
{
	int	size;

	size = 0;
	while (begin_list)
	{
		size++;
		begin_list = begin_list->next;
	}
	return (size);
}

void	ft_swap_data(void **data1, void **data2)
{
	void	*temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		len;
	int		idx;
	int		idx_cmp;
	t_list	*idx_list;

	len = _ft_list_size(*begin_list);
	idx = 0;
	while (idx < len)
	{
		idx_cmp = 0;
		idx_list = *begin_list;
		while (idx_cmp < len - 1 - idx)
		{
			if ((*cmp)(idx_list->data, idx_list->next->data) > 0)
				ft_swap_data(&idx_list->data, &idx_list->next->data);
			idx_list = idx_list->next;
			idx_cmp++;
		}
		idx++;
	}
}
