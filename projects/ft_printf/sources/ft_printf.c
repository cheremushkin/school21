/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:04:04 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_return(int len)
{
	if (len <= -1)
		return (-1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	char			*tmp;
	char			*pos;
	t_handler		handler;
	t_conv			conv;

	ft_init_handler(&handler);
	va_start(handler.args, str);
	tmp = (char *) str;
	pos = ft_strchr(tmp, '%');
	while (pos)
	{
		if (pos - tmp > 0)
			ft_print_handler(&handler, tmp, pos - tmp);
		if (ft_parse_conv(&conv, pos + 1)
			|| ft_handle_conv(&handler, &conv))
			return (ft_printf_return(handler.len));
		ft_print_handler(&handler, conv.out.str, conv.out.len);
		free(conv.out.str);
		tmp = conv.end;
		pos = ft_strchr(tmp, '%');
	}
	if (ft_strlen(tmp))
		ft_print_handler(&handler, tmp, ft_strlen(tmp));
	return (ft_printf_return(handler.len));
}
