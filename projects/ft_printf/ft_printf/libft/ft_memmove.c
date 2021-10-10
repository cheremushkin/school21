/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:08:28 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/04 20:51:17 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_last;
	unsigned char	*src_last;

	if (dst == NULL && src == NULL)
		return (dst);
	if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		dst_last = (unsigned char *) dst + n - 1;
		src_last = (unsigned char *) src + n - 1;
		while (n--)
			*dst_last-- = *src_last--;
	}
	return (dst);
}
