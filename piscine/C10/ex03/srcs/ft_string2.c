/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 23:00:14 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/05 20:23:37 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string2.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);
	while (*s1 && (*s1 == *s2) && (n-- > 1))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strrev(char *str)
{
	int		i;
	int		str_len;
	char	tmp;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len - i)
	{
		tmp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = tmp;
		i++;
	}
	return (str);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_strappend(char *dest, char *src)
{
	char	*str;

	str = (char *) malloc(ft_strlen(dest) + ft_strlen(src) + 1);
	if (str == NULL)
		return (NULL);
	ft_strcpy(str, dest);
	ft_strcpy(str + ft_strlen(dest), src);
	free(dest);
	return (str);
}

char	*ft_strappend_free(char *dest, char *src)
{
	char	*str;

	str = ft_strappend(dest, src);
	free(src);
	return (str);
}
