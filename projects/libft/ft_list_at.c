/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 00:24:57 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/16 22:11:00 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_at(t_list *head, unsigned int n)
{
	t_list			*elem;
	unsigned int	i;

	i = 0;
	elem = head;
	while (elem && i++ != n)
		elem = elem->next;
	return (elem);
}
