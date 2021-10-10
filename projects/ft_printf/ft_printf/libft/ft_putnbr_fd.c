/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:04:48 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 17:04:51 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	un;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		un = -1 * n;
	}
	else
		un = n;
	if (un > 9)
	{
		ft_putnbr_fd((int)(un / 10), fd);
		ft_putchar_fd((char)(un % 10 + '0'), fd);
	}
	else
		ft_putchar_fd((char)(un + '0'), fd);
}
