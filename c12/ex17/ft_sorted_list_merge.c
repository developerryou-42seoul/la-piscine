/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:39:26 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 19:22:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	_ft_insert_middle(t_list *idx_list, t_list *data_list, int (*cmp)())
{
	int		is_putted;
	t_list	*temp_list;

	is_putted = 0;
	while (idx_list->next)
	{
		if ((*cmp)(data_list->data, idx_list->next->data) < 0)
		{
			temp_list = idx_list->next;
			idx_list->next = data_list;
			idx_list->next->next = temp_list;
			is_putted = 1;
			break ;
		}
		idx_list = idx_list->next;
	}
	if (!is_putted)
		idx_list->next = data_list;
}

void	ft_list_insert(t_list **begin_list, t_list *data_list, int (*cmp)())
{
	t_list	*temp_list;

	if (*begin_list == 0)
	{
		*begin_list = data_list;
		return ;
	}
	if ((*cmp)(data_list->data, (*begin_list)->data) < 0)
	{
		temp_list = *begin_list;
		*begin_list = data_list;
		(*begin_list)->next = temp_list;
		return ;
	}
	_ft_insert_middle(*begin_list, data_list, cmp);
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)())
{
	t_list	*temp_list;

	while (begin_list2)
	{
		temp_list = begin_list2->next;
		ft_list_insert(begin_list1, begin_list2, cmp);
		begin_list2 = temp_list;
	}
}
