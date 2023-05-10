/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:54:30 by sryou             #+#    #+#             */
/*   Updated: 2022/02/22 19:39:07 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	maxnum;
	int	maxleft;
	int	maxright;

	if (root == 0)
		return (0);
	maxleft = btree_level_count(root->left);
	maxright = btree_level_count(root->right);
	if (maxleft < maxright)
		maxnum = maxright;
	else
		maxnum = maxleft;
	return (1 + maxnum);
}
