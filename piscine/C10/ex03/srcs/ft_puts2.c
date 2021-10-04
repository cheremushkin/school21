/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puts2.h"

void	ft_putstrn(char *str, int n)
{
	write(1, str, n);
}

void	ft_put_header(char *name, t_bool is_new_line)
{
	if (is_new_line)
		ft_putchar('\n');
	ft_putstr("==> ");
	ft_putstr(name);
	ft_putstr(" <===");
	ft_putchar('\n');
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	base_len;

	base_len = ft_check_base(base);
	if (!base_len)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		n = -1 * nbr;
	}
	else
		n = nbr;
	if (n < base_len)
		ft_putchar(base[n]);
	else
	{
		ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
}

void	ft_putnbr(int nb)
{
	ft_putnbr_base(nb, DECIMAL);
}
