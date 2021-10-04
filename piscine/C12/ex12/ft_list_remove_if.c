/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:24:57 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 22:11:48 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	ft_list_free_elem(t_list *elem, void (*free_fct)(void *))
{
	free_fct(elem->data);
	elem->next = NULL;
	free(elem);
}

void	ft_list_remove_if_head(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*current;

	current = *begin_list;
	while (current && cmp(current->data, data_ref) == 0)
	{
		*begin_list = current->next;
		ft_list_free_elem(current, free_fct);
		current = *begin_list;
	}
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref,
	int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*prev;
	t_list	*current;

	ft_list_remove_if_head(begin_list, data_ref, cmp, free_fct);
	prev = *begin_list;
	if (!prev)
		return ;
	current = (*begin_list)->next;
	while (current)
	{
		if (cmp(current->data, data_ref) == 0)
		{
			prev->next = current->next;
			ft_list_free_elem(current, free_fct);
			current = prev->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
