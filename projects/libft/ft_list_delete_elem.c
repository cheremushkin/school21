/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_delete_elem.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 21:11:34 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:13:55 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_delete_elem(t_list *elem, void (*del)(void *))
{
	if (!elem)
		return ;
	if (del)
		del(elem->content);
	free(elem);
}
