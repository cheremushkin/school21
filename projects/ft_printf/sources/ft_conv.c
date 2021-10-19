/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:54:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 22:32:56 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conv.h"

static int	ft_sanity_check(t_conv *conv)
{
	if (conv->width == -2 || conv->precision == -2)
		return (1);
	return (0);
}

int	ft_parse_conv(t_conv *conv, char *str)
{
	int	i;
	int	id;

	i = 0;
	ft_bzero(conv, sizeof(t_conv));
	ft_parse_flags(str, &(conv->flags), &i);
	conv->width = ft_parse_width(str, &i);
	while (str[i] != '.' && ft_get_conversion_id(str[i]) == -1 && str[i])
		i++;
	conv->precision = ft_parse_precision(str, &i);
	while (ft_get_conversion_id(str[i]) == -1 && str[i])
		i++;
	id = ft_get_conversion_id(str[i]);
	if (id == -1)
	{
		conv->end = str + i;
		return (1);
	}
	conv->code = str[i];
	conv->id = id;
	conv->end = str + i + 1;
	return (ft_sanity_check(conv));
}
