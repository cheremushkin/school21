/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 23:36:08 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/02 20:35:54 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int	n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -1 * nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
	else
		ft_putchar(n + '0');
}

int	check_last(int pref, int number)
{
	int	res;

	if (number % 10 != 9)
		return (0);
	res = 9;
	number = number / 10;
	while (number != 0)
	{
		if (res - 1 != number % 10)
			return (0);
		res = number % 10;
		number = number / 10;
	}
	if (res - 1 != pref)
		return (0);
	else
		return (1);
}

void	print_full(int cn, int n_digit, int n, int pref)
{
	int	d;

	d = cn % 10;
	while (d <= 9 + n_digit - n)
	{
		if (n_digit == n)
		{
			ft_putchar(pref + '0');
			ft_putnbr(cn - cn % 10 + d);
			if (check_last(pref, cn - cn % 10 + d) == 0)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		else
		{
			print_full((cn - cn % 10 + d) * 10 + d + 1, n_digit + 1, n, pref);
		}
		d++;
	}
}

void	ft_print_combn(int n)
{
	int	i;

	i = 0;
	while (i <= 10 - n)
	{
		if (n == 1)
		{
			ft_putchar(i + '0');
			if (i != 9)
			{
				ft_putchar(',');
				ft_putchar(' ');
			}
		}
		else
		{
			print_full(i + 1, 2, n, i);
		}
		i++;
	}
}
