/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:50:52 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/08 22:13:24 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == (char) c)
		{
			p = (char *) s;
			break ;
		}
		s++;
	}
	if (*s == (char) c)
		p = (char *) s;
	return (p);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	if (!dst || !src)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	ft_strjoin_(char const *s1, char const *s2, char **dst)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	dst_len;

	if (s1 == NULL || s2 == NULL)
		return (1);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dst_len = s1_len + s2_len;
	*dst = (char *) malloc(sizeof(char) * (dst_len + 1));
	if (*dst == NULL)
		return (1);
	*dst = ft_strncpy(*dst, s1, s1_len);
	ft_strncpy(*dst + s1_len, s2, s2_len);
	(*dst)[dst_len] = 0;
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dst;

	dst = (char *) malloc(sizeof(char) * (len + 1));
	dst = ft_strncpy(dst, s + start, len);
	if (!dst)
		return (NULL);
	dst[len] = 0;
	return (dst);
}
