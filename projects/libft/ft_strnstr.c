/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:39:33 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 00:21:43 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strnstr_util(const char *haystack, const char *needle)
{
	size_t	j;

	j = 0;
	while (needle[j])
	{
		if (haystack[j] == needle[j])
			j++;
		else
		{
			j = 0;
			break ;
		}
	}
	return (j);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *) haystack);
	i = 0;
	if (len < needle_len + 1)
		return (NULL);
	while (haystack[i] && i < len - needle_len + 1)
	{
		j = ft_strnstr_util(haystack + i, needle);
		if (j)
			return ((char *) haystack + i);
		i++;
	}
	return (NULL);
}
