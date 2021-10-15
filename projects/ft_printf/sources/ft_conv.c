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

void	ft_parse_conv(t_conv *conv, char *str)
{
	int	i;

	i = 0;
	ft_bzero(conv, sizeof(t_conv));
	ft_parse_flags(str, &(conv->flags), &i);
	conv->width = ft_parse_width(str, &i);
	while (str[i] != '.' && !ft_is_conv(str[i]) && str[i])
		i++;
	conv->precision = ft_parse_precision(str, &i);
	while (!ft_is_conv(str[i]) && str[i])
		i++;
	if (ft_is_conv(str[i]))
		conv->code = str[i];
	else
		return ;
	conv->end = str + i + 1;
}
