/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse_fun.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:19:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 22:12:06 by lteresia         ###   ########.fr       */
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

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list && i != nbr)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}

void	ft_list_swap_data(t_list *node1, t_list *node2)
{
	t_list	tmp;

	tmp.data = node2->data;
	node2->data = node1->data;
	node1->data = tmp.data;
}

void	ft_list_reverse_fun(t_list **begin_list)
{
	int	i;
	int	size;

	size = ft_list_size(*begin_list);
	i = 0;
	while (i < size - i)
	{
		ft_list_swap_data(ft_list_at(*begin_list, i),
			ft_list_at(*begin_list, size - i - 1));
		i++;
	}
}
