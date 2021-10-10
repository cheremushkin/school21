/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:06:39 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:07:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size;
	t_list	*elem;

	size = 0;
	elem = lst;
	while (elem != NULL)
	{
		elem = elem->next;
		size++;
	}
	return (size);
}
