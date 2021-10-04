/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:24:33 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 18:34:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.h"

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	sign;

	i = 0;
	n = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (ft_is_sign(*str))
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (ft_is_digit(*str))
		n = n * 10 + *str++ - '0';
	return (sign * n);
}
