/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 19:36:32 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/17 23:27:54 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count_rec(t_btree *root, int n_levels)
{
	int	n_left;
	int	n_right;

	if (!root)
		return (n_levels);
	n_left = btree_level_count_rec(root->left, n_levels + 1);
	n_right = btree_level_count_rec(root->right, n_levels + 1);
	if (n_left > n_right)
		return (n_left);
	return (n_right);
}

int	btree_level_count(t_btree *root)
{
	return (btree_level_count_rec(root, 0));
}
