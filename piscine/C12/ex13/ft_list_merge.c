/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:19:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 17:32:17 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*elem;

	elem = begin_list;
	while (elem->next)
		elem = elem->next;
	return (elem);
}

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	if (*begin_list1)
		ft_list_last(*begin_list1)->next = begin_list2;
	else
		*begin_list1 = begin_list2;
}
