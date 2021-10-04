/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 04:27:24 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/04 06:23:11 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

void	ft_puthex(char c)
{
	if (c <= 9)
		ft_putchar(c + '0');
	else
		ft_putchar('a' + c - 10);
}

void	ft_putchar_hex(char c)
{
	ft_putchar(c / 16 + '0');
	ft_puthex(c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	while (1)
	{
		if (*str == '\0')
			break ;
		if (ft_is_printable(*str))
			ft_putchar(*str);
		else
		{
			ft_putchar('\\');
			ft_putchar_hex(*str);
		}
		str++;
	}
}
