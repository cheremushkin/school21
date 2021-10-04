/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:17:42 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	return (dest);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	dest = (char *) malloc(sizeof(char) * n);
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strappend_char(char *dest, char *c)
{
	char	*str;
	int		dest_len;

	dest_len = ft_strlen(dest);
	str = (char *) malloc(dest_len + 2);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, dest);
	str[dest_len] = *c;
	str[dest_len + 1] = '\0';
	free(dest);
	return (str);
}
