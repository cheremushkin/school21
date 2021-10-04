/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:36:32 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/17 23:40:26 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_btree.h"

typedef struct s_queue_ft
{
	struct s_queue_ft	*next;
	t_btree				*node;
	int					level;
	int					left;
}	t_queue_ft;

void	ft_queue(t_queue_ft **head, t_btree *node, int level, int left)
{
	t_queue_ft	*current;
	t_queue_ft	*elem;

	if (!node)
		return ;
	elem = (t_queue_ft *) malloc(sizeof(t_queue_ft));
	if (!elem)
		return ;
	elem->node = node;
	elem->next = NULL;
	elem->level = level;
	elem->left = left;
	if (!*head)
		*head = elem;
	else
	{
		current = *head;
		while (current->next)
			current = current->next;
		current->next = elem;
	}
}

t_queue_ft	*ft_dequeue(t_queue_ft **head)
{
	t_queue_ft	*elem;

	if (!*head)
		return (NULL);
	elem = *head;
	*head = (*head)->next;
	return (elem);
}

void	btree_apply_by_level(t_btree *root,
	void (*applyf)(void *item, int current_level, int is_first_elem))
{
	t_queue_ft	*head;
	t_queue_ft	*elem;

	if (!root)
		return ;
	head = NULL;
	ft_queue(&head, root, 0, 1);
	elem = ft_dequeue(&head);
	while (elem)
	{
		applyf(elem->node->item, elem->level, elem->left);
		ft_queue(&head, elem->node->left, elem->level + 1, elem->left);
		ft_queue(&head, elem->node->right, elem->level + 1, 0);
		free(elem);
		elem = ft_dequeue(&head);
	}
}
