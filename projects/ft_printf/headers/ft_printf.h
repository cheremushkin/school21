/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 02:59:40 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_eval.h"
# include "ft_evals.h"
# include "ft_convs.h"

typedef struct s_parser_elem
{
	char					*start;
	size_t 					len;
	t_conv					*conv;
	struct s_parser_elem	*next;
}	t_parser_elem;

typedef struct s_parser
{
	va_list			args;
	int				(*evals[9])(va_list args, t_conv *conv);
	t_parser_elem	*head;
	t_parser_elem	*tail;
	size_t			size;
	size_t			len;
}	t_parser;

int				ft_printf(const char *str, ...);
t_parser		*ft_init_parser(void);
void			ft_parser_push(t_parser *parser, t_parser_elem *elem);
t_parser_elem	*ft_init_parser_elem(char *start, size_t len, t_conv *specs);
void			ft_print_parser(char *str, t_parser *parser);
void			ft_free_parser(t_parser *parser);

#endif