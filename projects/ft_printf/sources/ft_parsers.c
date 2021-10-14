/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:54:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 22:32:56 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsers.h"

int	ft_is_conv(char c)
{
	return ((ft_strchr(CONVS, c) - (char *) CONVS) >= 0);
}

t_flags *ft_parse_flags(char *str, int *i)
{
	t_flags	*flags;

	flags = (t_flags *) ft_calloc(1, sizeof(t_flags));
	while (!(ft_isdigit(str[*i]) && str[*i] != '0')
			&& str[*i] != '.'
			&& !ft_is_conv(str[*i])
			&& str[*i])
	{
		if (str[*i] == '-')
			flags->minus = 1;
		else if (str[*i] == '+')
			flags->plus = 1;
		else if (str[*i] == '0')
			flags->zero = 1;
		else if (str[*i] == '#')
			flags->hash = 1;
		else if (str[*i] == ' ')
			flags->space = 1;
		(*i)++;
	}
	return (flags);
}

int	ft_parse_n(char *str, int *i)
{
	int	n;

	n = 0;
	while (ft_isdigit(str[*i]))
		n = n * 10 + str[(*i)++] - '0';
	return n;
}

int	ft_parse_width(char *str, int *i)
{
	return ft_parse_n(str, i);
}

int	ft_parse_precision(char *str, int *i)
{
	if (str[*i] == '.')
	{
		(*i)++;
		return (ft_parse_n(str, i));
	}
	return (-1);
}
