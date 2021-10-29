/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:46:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:50:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_map(t_list *head, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*elem;

	if (!f)
		return (NULL);
	new = NULL;
	elem = head;
	while (head)
	{
		tmp = ft_list_create_elem(f(elem->content));
		if (!tmp)
		{
			ft_list_delete(&new, del);
			return (NULL);
		}
		ft_list_push_back(&new, tmp);
		elem = elem->next;
	}
	return (new);
}
