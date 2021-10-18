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

static void	ft_itoa_reverse(long long n, char *dst)
{
	int					i;
	int					sign;
	unsigned long long	un;

	sign = 1;
	i = 0;
	if (n < 0)
	{
		sign = -1;
		un = (unsigned long long) -1 * n;
	}
	else
		un = (unsigned long long) n;
	if (!un)
		dst[i++] = '0';
	while (un)
	{
		dst[i++] = (char)(un % 10 + '0');
		un /= 10;
	}
	if (sign == -1)
		dst[i++] = '-';
	dst[i] = '\0';
}

char	*ft_itoa(long long n)
{
	char	dst[65];

	ft_itoa_reverse(n, dst);
	return (ft_strrev(ft_strdup(dst)));
}
