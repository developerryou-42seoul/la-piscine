/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:06 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 15:19:53 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*lst_idx;
	t_list	*new;

	lst_idx = *begin_list;
	new = ft_create_elem(data);
	if (lst_idx == 0)
	{
		*begin_list = new;
		return ;
	}
	while (lst_idx->next)
		lst_idx = lst_idx->next;
	lst_idx->next = new;
}
