/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ops.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 18:08:48 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 19:07:45 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ops.h"

void	ft_putsum(int n, int m)
{
	ft_putnbr(n + m);
	ft_putstr("\n");
}

void	ft_putsubstr(int n, int m)
{
	ft_putnbr(n - m);
	ft_putstr("\n");
}

void	ft_putmult(int n, int m)
{
	ft_putnbr(n * m);
	ft_putstr("\n");
}

void	ft_putdiv(int n, int m)
{
	if (m == 0)
		return (ft_putstr("Stop : division by zero\n"));
	ft_putnbr(n / m);
	ft_putstr("\n");
}

void	ft_putmod(int n, int m)
{
	if (m == 0)
		return (ft_putstr("Stop : modulo by zero\n"));
	ft_putnbr(n % m);
	ft_putstr("\n");
}
