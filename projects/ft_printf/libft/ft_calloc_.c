/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:54:36 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/04 21:08:21 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_calloc_(void **p, size_t count, size_t size)
{
	*p = ft_calloc(count, size);
	if (!*p)
		return (1);
	return (0);
}
