/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:14:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:17:44 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	return (dest);
}

char	*ft_strnjoin_by_lb(char **strs, int n_strings,
	int len_sting, int dest_len)
{
	int		i;
	char	*dest;
	int		pointer;

	i = 0;
	dest = (char *) malloc(sizeof(char) * dest_len);
	if (dest == NULL)
		return (NULL);
	i = 0;
	pointer = 0;
	while (i < n_strings)
	{
		ft_strncpy(dest + pointer, strs[i], len_sting);
		pointer += len_sting;
		dest[pointer] = '\n';
		pointer += 1;
		i++;
	}
	return (dest);
}
