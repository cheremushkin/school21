/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 19:30:37 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/04 19:33:56 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dstsize)
		return (src_len);
	i = 0;
	while (i < dstsize - 1)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			return (src_len);
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}
