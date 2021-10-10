/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:04:04 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 04:31:34 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_is_conversion(char c)
{
	return ((int) (ft_strchr(CONVERSIONS, c) - (char *) 0));
}

t_specs	*ft_parse_specs(char *str)
{
	int	i;
	t_specs	*specs;

	specs = (t_specs *) malloc(sizeof(t_specs));

	i = 0;
	while (!ft_is_conversion(str[i]))
		i++;
	specs->output = "$$";
	specs->len = 2;
	specs->end = str + i + 1;
	return (specs);
}

void	ft_printf(const char *str, ...)
{
	char		*tmp;
	char		*pos;
	t_printf	*printf;
	t_specs		*specs;

	printf = (t_printf *) malloc(sizeof(t_printf));
	printf->head = NULL;
	printf->tail = NULL;
	printf->size = 0;
	printf->len = 0;

	tmp = (char *) str;
	pos = ft_strchr(tmp, '%');
	while (pos)
	{
		if (pos - tmp > 0)
			ft_printf_push(printf, ft_init_printf_elem(tmp, pos - tmp, NULL));
		specs = ft_parse_specs(pos + 1);
		ft_printf_push(printf, ft_init_printf_elem(NULL, specs->len, specs));
		tmp = specs->end;
		pos = ft_strchr(tmp, '%');
	}
	if (ft_strlen(tmp))
		ft_printf_push(printf, ft_init_printf_elem(tmp, ft_strlen(tmp), NULL));
	ft_print_printf((char *) str, printf);
}