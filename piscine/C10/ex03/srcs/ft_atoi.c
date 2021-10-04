/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:24:33 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/06 19:24:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_find_digit_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	return (ft_atoi_base(str, DECIMAL));
}

int	ft_atoi_base(char *str, char *base)
{
	int				i;
	int				n;
	int				sign;
	unsigned int	base_len;

	base_len = ft_check_base(base);
	if (!base_len)
		return (0);
	i = 0;
	n = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (ft_find_digit_pos(*str, base) != -1)
		n = n * base_len + ft_find_digit_pos(*str++, base);
	return (sign * n);
}
