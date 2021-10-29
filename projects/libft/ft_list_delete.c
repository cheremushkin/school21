/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:14:05 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:32:13 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_delete(t_list **head, void (*del)(void *))
{
	t_list	*tmp;

	if (!head)
		return ;
	while (*head)
	{
		tmp = *head;
		(*head) = (*head)->next;
		ft_list_delete_elem(tmp, del);
	}
}
