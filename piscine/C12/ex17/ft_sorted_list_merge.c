/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:19:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 22:12:40 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_sorted_list_merge_rec(t_list *node1, t_list *node2, int (*cmp)())
{
	if (!node1)
		return (node2);
	if (!node2)
		return (node1);
	if (cmp(node1->data, node2->data) < 0)
	{
		node1->next = ft_sorted_list_merge_rec(node1->next, node2, cmp);
		return (node1);
	}
	else
	{
		node2->next = ft_sorted_list_merge_rec(node1, node2->next, cmp);
		return (node2);
	}
}

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	*begin_list1 = ft_sorted_list_merge_rec(*begin_list1, begin_list2, cmp);
}
