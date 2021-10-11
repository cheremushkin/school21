/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:29:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 21:59:24 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		src_len;

	src_len = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (src_len + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_memcpy(dest, src, src_len + 1));
}
