/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:17:14 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/05 20:21:07 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(int len, char first, char middle, char last)
{
	int	i;

	if (len > 0)
		ft_putchar(first);
	i = 1;
	while (i < len - 1)
	{
		ft_putchar(middle);
		i++;
	}
	if (i < len)
		ft_putchar(last);
	if (len > 0)
		ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (y > 0)
		ft_putline(x, '/', '*', '\\');
	i = 1;
	while (i < y - 1)
	{
		ft_putline(x, '*', ' ', '*');
		i++;
	}
	if (i < y)
		ft_putline(x, '\\', '*', '/');
}
