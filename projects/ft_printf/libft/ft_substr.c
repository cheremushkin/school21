/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:01:18 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 18:22:12 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		size;

	if (s == NULL)
		return (NULL);
	size = ft_min((int) len, ft_max((int) ft_strlen(s) - start, 0)) + 1;
	dst = (char *) malloc(sizeof(char) * size);
	if (dst == NULL)
		return (NULL);
	ft_strlcpy(dst, s + start, size);
	return (dst);
}
