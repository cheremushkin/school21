/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:08:58 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 17:32:37 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strrev(char *str)
{
	unsigned int	i;
	size_t			str_len;
	char			tmp;

	if (!str)
		return (NULL);
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

static void	ft_itoa_rev(int n, char *dst)
{
	int				i;
	int				sign;
	unsigned int	un;

	sign = 1;
	i = 0;
	if (n < 0)
	{
		sign = -1;
		un = (unsigned int) -1 * n;
	}
	else
		un = (unsigned int) n;
	if (!un)
		dst[i++] = '0';
	while (un)
	{
		dst[i++] = (char)(un % 10 + '0');
		un /= 10;
	}
	if (sign == -1)
		dst[i++] = '-';
	dst[i] = 0;
}

char	*ft_itoa(int n)
{
	char	dst[12];

	ft_itoa_rev(n, dst);
	return (ft_strrev(ft_strdup(dst)));
}
