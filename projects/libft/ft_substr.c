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

static unsigned int	ft_min(unsigned int const n, unsigned int const m)
{
	if (n > m)
		return (m);
	return (n);
}

static unsigned int	ft_sub_to_zero(unsigned int const n, unsigned int const m)
{
	if (n > m)
		return (n - m);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	size;

	if (!s)
		return (NULL);
	size = ft_min(len, ft_sub_to_zero(ft_strlen(s), start)) + 1;
	dst = (char *) malloc(sizeof(char) * size);
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s + start, size);
	return (dst);
}
