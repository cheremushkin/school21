/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dumps.h"

void	ft_hexdump_addr(int addr)
{
	int		i;
	char	*addr_hex;
	int		addr_hex_len;

	addr_hex = ft_itoa_base(addr, HEXADECIMAL);
	addr_hex_len = ft_strlen(addr_hex);
	i = 0;
	while (i++ < ADDR_LEN - addr_hex_len)
		ft_putnbr(0);
	ft_putstr(addr_hex);
}

void	ft_hexdump_fill_zero(int start, t_bool option)
{
	int	i;

	i = start;
	while (i < LINE_LEN)
	{
		ft_putstr("  ");
		if (i != LINE_LEN - 1)
			ft_putstr(" ");
		if (i == LINE_LEN / 2 - 1 && option)
			ft_putstr(" ");
		i++;
	}
}

void	ft_hexdump_content_line(char *line, int len, t_bool option)
{
	int		i;
	char	*char_hex;

	ft_putstr(" ");
	if (option)
		ft_putstr(" ");
	i = 0;
	while (i < len)
	{
		char_hex = ft_itoa_base((int) line[i], HEXADECIMAL);
		if (ft_strlen(char_hex) == 1)
			ft_putnbr(0);
		ft_putstr(char_hex);
		if (i != LINE_LEN - 1)
			ft_putstr(" ");
		if (i == LINE_LEN / 2 - 1 && option)
			ft_putstr(" ");
		i++;
	}
	if (i < LINE_LEN)
		ft_hexdump_fill_zero(i, option);
}

void	ft_dump_content_line(char *line, int len)
{
	int		i;

	ft_putstr("  |");
	i = 0;
	while (i < len)
	{
		if (line[i] >= 32 && line[i] <= 126)
			ft_putchar(line[i]);
		else
			ft_putchar('.');
		i++;
	}
	ft_putstr("|");
}

void	ft_hexdump_line(char *content, int addr, t_bool option)
{
	ft_hexdump_addr(addr);
	if (addr != ft_strlen(content))
	{
		ft_hexdump_content_line(content + addr,
			ft_min(LINE_LEN, ft_strlen(content + addr)), option);
		if (option)
			ft_dump_content_line(content + addr,
				ft_min(LINE_LEN, ft_strlen(content + addr)));
	}
	ft_putstr("\n");
}
