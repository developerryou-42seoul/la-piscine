/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:28:21 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 19:07:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list	*ft_remove_first(t_list *idx_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*temp_list;

	while (idx_list && (*cmp)(idx_list->data, data_ref) == 0)
	{
		temp_list = idx_list;
		idx_list = idx_list->next;
		(*free_fct)(temp_list->data);
		free(temp_list);
	}
	return (idx_list);
}

void	ft_remove_middle(t_list *idx_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*temp_list;

	while (idx_list && idx_list->next)
	{
		if ((*cmp)(idx_list->next->data, data_ref) == 0)
		{
			temp_list = idx_list->next;
			idx_list->next = idx_list->next->next;
			(*free_fct)(temp_list->data);
			free(temp_list);
		}
		else
			idx_list = idx_list->next;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
		int (*cmp)(), void (*free_fct)(void *))
{
	if (*begin_list == 0)
		return ;
	*begin_list = ft_remove_first(*begin_list, data_ref, cmp, free_fct);
	ft_remove_middle(*begin_list, data_ref, cmp, free_fct);
}
