/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:04:04 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 19:53:00 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_eval_specs(t_printf *printf, t_conversion *specs)
{
	if (specs->conversion == 'd')
		specs->output = printf->evals[0](printf);
	specs->len = ft_strlen(specs->output);
}

void	ft_printf(const char *str, ...)
{
	char			*tmp;
	char			*pos;
	t_printf		*printf;
	t_conversion	*specs;

	printf = ft_init_printf();
	va_start(printf->args, str);

	tmp = (char *) str;
	pos = ft_strchr(tmp, '%');
	while (pos)
	{
		if (pos - tmp > 0)
			ft_printf_push(printf, ft_init_printf_elem(tmp, pos - tmp, NULL));
		specs = ft_parse_conversion(pos + 1);
		ft_eval_specs(printf, specs);
		ft_printf_push(printf, ft_init_printf_elem(NULL, specs->len, specs));
		tmp = specs->end;
		pos = ft_strchr(tmp, '%');
	}
	if (ft_strlen(tmp))
		ft_printf_push(printf, ft_init_printf_elem(tmp, ft_strlen(tmp), NULL));
	ft_print_printf((char *) str, printf);
	ft_free_printf(printf);
}