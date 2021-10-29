/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:08:10 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:08:47 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_last(t_list *head)
{
	t_list	*elem;

	elem = head;
	if (!elem)
		return (NULL);
	while (elem->next)
		elem = elem->next;
	return (elem);
}
