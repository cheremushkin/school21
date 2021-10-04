/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:14:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:48 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa.h"

void	ft_itoa_rev_inplace(int nbr, char *base, char *dest)
{
	int				i;
	int				sign;
	unsigned int	n;
	unsigned int	base_len;

	base_len = ft_check_base(base);
	sign = 1;
	i = 0;
	if (nbr < 0)
	{
		sign = -1;
		n = -1 * nbr;
	}
	else
		n = nbr;
	if (n == 0)
		dest[i++] = base[0];
	while (n != 0)
	{
		dest[i++] = base[n % base_len];
		n /= base_len;
	}
	if (sign == -1)
		dest[i++] = '-';
	dest[i] = '\0';
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	converted[33];

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	ft_itoa_rev_inplace(n, base_to, converted);
	return (ft_strrev(ft_strdup(converted)));
}

char	*ft_itoa_base(int nbr, char *base_to)
{
	char	converted[33];

	ft_itoa_rev_inplace(nbr, base_to, converted);
	return (ft_strrev(ft_strdup(converted)));
}
