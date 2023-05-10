/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 16:51:56 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 12:36:54 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
		int (*cmpf)(void *, void *))
{
	void	*item;

	if (root == 0)
		return (0);
	item = 0;
	if ((*cmpf)(root->item, data_ref) == 0)
		return (root->item);
	if (root->left)
	{
		item = btree_search_item(root->left, data_ref, cmpf);
		if (item)
			return (item);
	}
	if (root->right)
	{
		item = btree_search_item(root->right, data_ref, cmpf);
		if (item)
			return (item);
	}
	return (0);
}
