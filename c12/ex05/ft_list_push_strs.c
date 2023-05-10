/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:07:32 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 15:25:13 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*lst;
	t_list	*temp;
	int		idx;

	lst = 0;
	temp = 0;
	idx = 0;
	while (idx < size)
	{
		lst = ft_create_elem(strs[idx]);
		lst->next = temp;
		temp = lst;
		idx++;
	}
	return (lst);
}
