/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_puts.h"

void	ft_putchar(char c)
{	
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{	
	while (*str)
		ft_putchar(*str++);
}

void	ft_putchar_error(char c)
{	
	write(2, &c, 1);
}

void	ft_putstr_error(char *str)
{	
	while (*str)
		ft_putchar_error(*str++);
}
