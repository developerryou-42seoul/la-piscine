/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:12:07 by sryou             #+#    #+#             */
/*   Updated: 2022/02/23 12:58:59 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"
#include <stdlib.h>

typedef struct s_queue
{
	t_btree			*node;
	int				level;
	struct s_queue	*next;
}	t_queue;

t_queue	*g_queue;

t_queue	*create_queue(t_btree *node, int level)
{
	t_queue	*queue;

	queue = (t_queue *)malloc(sizeof(t_queue));
	if (queue == 0)
		return (0);
	queue->node = node;
	queue->level = level;
	queue->next = 0;
	return (queue);
}

void	pop(void)
{
	t_queue	*temp_que;

	if (g_queue != 0)
	{
		temp_que = g_queue;
		g_queue = g_queue->next;
		free(temp_que);
	}
}

void	push(t_btree *node, int level)
{
	t_queue	*idx_que;

	if (g_queue == 0)
	{
		g_queue = create_queue(node, level);
		return ;
	}
	idx_que = g_queue;
	while (idx_que->next)
		idx_que = idx_que->next;
	idx_que->next = create_queue(node, level);
}

int	init_queue(t_btree *root)
{
	g_queue = create_queue(root, 0);
	if (g_queue == 0)
		return (1);
	return (0);
}

void	btree_apply_by_level(t_btree *root,
		void (*applyf)(void *item, int current_level, int is_first))
{
	int		flag_level;
	t_btree	*node;

	g_queue = 0;
	if (root == 0 || init_queue(root))
		return ;
	flag_level = -1;
	while (g_queue != 0)
	{
		node = g_queue->node;
		if (node->left)
			push(node->left, g_queue->level + 1);
		if (node->right)
			push(node->right, g_queue->level + 1);
		if (flag_level < g_queue->level)
		{
			flag_level = g_queue->level;
			(*applyf)(node->item, flag_level, 1);
		}
		else
			(*applyf)(node->item, flag_level, 0);
		pop();
	}
}
