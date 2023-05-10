/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:09:42 by sryou             #+#    #+#             */
/*   Updated: 2022/02/21 16:12:09 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*idx;
	t_list	*before_idx;
	t_list	*temp;

	idx = *begin_list;
	before_idx = 0;
	while (idx)
	{
		temp = idx->next;
		idx->next = before_idx;
		before_idx = idx;
		idx = temp;
	}
	*begin_list = before_idx;
}
