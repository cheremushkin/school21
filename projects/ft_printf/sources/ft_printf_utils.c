/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:41:35 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 22:30:29 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_parser	*ft_init_parser(void)
{
	t_parser	*parser;

	parser = (t_parser *) malloc(sizeof(t_parser));
	parser->head = NULL;
	parser->tail = NULL;
	parser->size = 0;
	parser->len = 0;
	parser->evals[0] = ft_eval_char;
	parser->evals[1] = ft_eval_string;
	parser->evals[3] = ft_eval_int;
	parser->evals[4] = ft_eval_int;
	parser->evals[5] = ft_eval_uint;
	parser->evals[8] = ft_eval_percent;
	return (parser);
}

void	ft_parser_push(t_parser *parser, t_parser_elem *elem)
{
	if (!parser->size)
	{
		parser->head = elem;
		parser->tail = elem;
	}
	else
	{
		parser->tail->next = elem;
		parser->tail = elem;
	}
	parser->size++;
	parser->len += elem->len;
}

t_parser_elem	*ft_init_parser_elem(char *start, size_t len, t_conv *conv)
{
	t_parser_elem	*elem;

	elem = (t_parser_elem *) malloc(sizeof(t_parser_elem));
	elem->start = start;
	elem->len = len;
	elem->specs = conv;
	elem->next = NULL;
	return (elem);
}

void	ft_print_parser(char *str, t_parser *parser)
{
	t_parser_elem	*elem;

	elem = parser->head;
	while (elem)
	{
		if (elem->start)
			write(1, elem->start, elem->len);
		else
			write(1, elem->specs->output, elem->len);
		elem = elem->next;
	}
}

void	ft_free_parser(t_parser *parser)
{
	free(parser);
}
