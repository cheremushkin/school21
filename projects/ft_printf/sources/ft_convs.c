/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:54:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 22:32:56 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_convs.h"
#include <stdio.h>

t_conv	*ft_parse(char *str)
{
	int		i;
	t_conv	*conv;

	conv = (t_conv *) malloc(sizeof(t_conv));
	i = 0;
	conv->flags = ft_parse_flags(str, &i);
	conv->width = ft_parse_n(str, &i);
	while (str[i] != '.' && !ft_is_conv(str[i]) && str[i])
		i++;
	conv->precision = ft_parse_precision(str, &i);
	while (!ft_is_conv(str[i]) && str[i])
		i++;
	if (ft_is_conv(str[i]))
		conv->code = str[i];
	else
		return (NULL);
	conv->end = str + i + 1;
	return (conv);
}
