/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:36:32 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/17 23:27:43 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref,
	int (*cmpf)(void *, void *))
{
	t_btree	*item;

	if (!root)
		return ((void *) 0);
	item = btree_search_item(root->left, data_ref, cmpf);
	if (item)
		return (item);
	if (!cmpf(root->item, data_ref))
		return (root->item);
	return (btree_search_item(root->right, data_ref, cmpf));
}
