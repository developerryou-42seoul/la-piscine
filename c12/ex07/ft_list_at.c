/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:09:16 by sryou             #+#    #+#             */
/*   Updated: 2022/02/21 16:09:18 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	idx;

	idx = 0;
	while (idx < nbr)
	{
		if (begin_list == 0)
			return (0);
		begin_list = begin_list->next;
		idx++;
	}
	return (begin_list);
}
