/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:19:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 22:12:25 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*elem;
	t_list	*current;

	elem = ft_create_elem(data);
	if (!*begin_list || cmp(elem->data, (*begin_list)->data) < 0)
	{
		elem->next = *begin_list;
		*begin_list = elem;
		return ;
	}
	current = *begin_list;
	while (current->next && cmp(elem->data, current->next->data) > 0)
		current = current->next;
	elem->next = current->next;
	current->next = elem;
}
