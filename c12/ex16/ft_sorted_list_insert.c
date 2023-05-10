/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 21:29:26 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 19:24:13 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_insert_middle(t_list *idx_list, void *data, int (*cmp)())
{
	int		is_putted;
	t_list	*temp_list;

	is_putted = 0;
	while (idx_list->next)
	{
		if ((*cmp)(data, idx_list->next->data) < 0)
		{
			temp_list = idx_list->next;
			idx_list->next = ft_create_elem(data);
			idx_list->next->next = temp_list;
			is_putted = 1;
			break ;
		}
		idx_list = idx_list->next;
	}
	if (!is_putted)
		idx_list->next = ft_create_elem(data);
}

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*temp_list;

	if (*begin_list == 0)
	{
		*begin_list = ft_create_elem(data);
		return ;
	}
	if ((*cmp)(data, (*begin_list)->data) < 0)
	{
		temp_list = *begin_list;
		*begin_list = ft_create_elem(data);
		(*begin_list)->next = temp_list;
		return ;
	}
	ft_insert_middle(*begin_list, data, cmp);
}
