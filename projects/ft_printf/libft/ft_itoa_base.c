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

static size_t	ft_uitoa_reverse(unsigned long long n,
									char *dst, const char *base)
{
	size_t	i;
	size_t	base_len;

	i = 0;
	base_len = ft_strlen(base);
	if (!n)
		dst[i++] = '0';
	while (n)
	{
		dst[i++] = base[n % base_len];
		n /= base_len;
	}
	dst[i] = 0;
	return (i);
}

static void	ft_itoa_reverse(long long n, char *dst, const char *base)
{
	int					sign;
	size_t				i;
	unsigned long long	un;

	sign = 1;
	if (n < 0)
	{
		sign = -1;
		un = (unsigned long long) -1 * n;
	}
	else
		un = (unsigned long long) n;
	i = ft_uitoa_reverse(un, dst, base);
	if (sign == -1)
		dst[i++] = '-';
	dst[i] = 0;
}

char	*ft_itoa_base(long long n, const char *base)
{
	char	dst[65];

	ft_itoa_reverse(n, dst, base);
	return (ft_strrev(ft_strdup(dst)));
}

char	*ft_uitoa_base(unsigned long long n, const char *base)
{
	char	dst[65];

	ft_uitoa_reverse(n, dst, base);
	return (ft_strrev(ft_strdup(dst)));
}
