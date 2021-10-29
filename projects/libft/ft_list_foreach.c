/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:33:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:35:21 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_foreach(t_list *head, void (*f)(void *))
{
	t_list	*elem;

	elem = head;
	while (elem)
	{
		f(elem->content);
		elem = elem->next;
	}
}
