/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:19:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 18:40:29 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	int		size;
	t_list	*elem;

	size = 0;
	elem = begin_list;
	while (elem != (void *) 0)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}

t_list	*ft_list_swap(t_list *node1, t_list *node2)
{
	t_list	*tmp;

	tmp = node2->next;
	node2->next = node1;
	node1->next = tmp;
	return (node2);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int		i;
	int		j;
	int		size;
	t_list	*node;
	t_list	**prev_p;

	size = ft_list_size(*begin_list);
	i = 0;
	while (i < size)
	{
		j = 0;
		prev_p = begin_list;
		while (j < size - i - 1)
		{
			node = *prev_p;
			if (cmp(node->data, node->next->data) > 0)
				*prev_p = ft_list_swap(node, node->next);
			prev_p = &((*prev_p)->next);
			j++;
		}
		i++;
	}
}
