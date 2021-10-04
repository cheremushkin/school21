/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:24:33 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/06 19:24:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_is_sign(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

unsigned int	ft_check_base(char *base)
{
	int				i;
	int				hash[255];
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (i < 255)
		hash[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (ft_is_sign(base[i]) || hash[(int) base[i]]
			|| base[i] < 32 || base[i] > 126)
			return (0);
		hash[(int) base[i]] = 1;
		i++;
	}
	return (base_len);
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
