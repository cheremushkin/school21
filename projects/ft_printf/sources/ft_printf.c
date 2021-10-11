/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:04:04 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 22:35:29 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	char			*tmp;
	char			*pos;
	t_parser		*parser;
	t_conv	*conv;

	parser = ft_init_parser();
	va_start(parser->args, str);

	tmp = (char *) str;
	pos = ft_strchr(tmp, '%');
	while (pos)
	{
		if (pos - tmp > 0)
			ft_parser_push(parser, ft_init_parser_elem(tmp, pos - tmp, NULL));
		conv = ft_parse_conv(pos + 1);
		ft_eval_conv(parser->args, parser->evals, conv);
		ft_parser_push(parser, ft_init_parser_elem(NULL, conv->len, conv));
		tmp = conv->end;
		pos = ft_strchr(tmp, '%');
	}
	if (ft_strlen(tmp))
		ft_parser_push(parser, ft_init_parser_elem(tmp, ft_strlen(tmp), NULL));
	ft_print_parser((char *) str, parser);
	return (parser->len);
	//ft_free_parser(parser);
}
