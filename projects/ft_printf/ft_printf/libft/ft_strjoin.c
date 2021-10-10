/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:13:01 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 16:50:58 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dst_len;
	char	*dst;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst_len = s1_len + s2_len;
	dst = (char *) malloc(sizeof(char) * (dst_len + 1));
	if (dst == NULL)
		return (NULL);
	dst = ft_memcpy(dst, s1, s1_len);
	ft_memcpy(dst + s1_len, s2, s2_len);
	dst[dst_len] = '\0';
	return (dst);
}
