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
