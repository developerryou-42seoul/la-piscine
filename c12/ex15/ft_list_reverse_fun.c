/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 19:44:54 by sryou             #+#    #+#             */
/*   Updated: 2022/02/21 16:15:45 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	__ft_list_size(t_list *begin_list)
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

void	_ft_swap_data(void **data1, void **data2)
{
	void	*temp;

	temp = *data1;
	*data1 = *data2;
	*data2 = temp;
}

t_list	*_ft_list_at(t_list *begin_list, unsigned int nbr)
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

void	ft_list_reverse_fun(t_list *begin_list)
{
	int	size;
	int	idx;

	size = __ft_list_size(begin_list);
	idx = 0;
	while (idx < size / 2)
	{
		_ft_swap_data(&(_ft_list_at(begin_list, idx)->data),
			&(_ft_list_at(begin_list, size - 1 - idx)->data));
		idx++;
	}
}
