/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:06:19 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 22:10:15 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem == (void *) 0)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	int		i;
	t_list	*begin_list;

	i = 0;
	begin_list = (void *) 0;
	while (i < size)
		ft_list_push_front(&begin_list, (void *) strs[i++]);
	return (begin_list);
}
