/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 18:26:59 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/06 15:35:59 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
static int	ft_istrimable(char c, unsigned char *hash)
{
	return (hash[(int) c]);
}

static int	ft_lstrtrim(char const *s, unsigned char *hash)
{
	int	i;

	i = 0;
	while (s[i] && ft_istrimable(s[i], hash))
		i++;
	return (i);
}

static int	ft_rstrtrim(char const *s, unsigned char *hash)
{
	int	i;

	i = (int) ft_strlen(s) - 1;
	while (i >= 0 && ft_istrimable(s[i], hash))
		i--;
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned char	hash[256];
	int	l_pos;
	int	r_pos;

	if (!s1)
		return (NULL);
	ft_bzero(hash, 256);
	while (*set)
		hash[(int) *(set++)] = 1;
	r_pos = ft_rstrtrim(s1, hash);
	if (r_pos == -1)
		return (ft_strdup(""));
	l_pos = ft_lstrtrim(s1, hash);
	return (ft_substr(s1, l_pos, r_pos - l_pos + 1));
}
