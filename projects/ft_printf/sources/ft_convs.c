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

int	ft_is_conv(char c)
{
	return ((ft_strchr(CONVS, c) - (char *) CONVS) >= 0);
}

t_conv	*ft_parse_conv(char *str)
{
	int		i;
	t_conv	*conv;

	conv = (t_conv *) malloc(sizeof(t_conv));
	i = 0;
	while (!ft_is_conv(str[i]))
		i++;
	conv->conv = str[i];
	conv->end = str + i + 1;
	return (conv);
}

void	ft_eval_conv(va_list args,
			void (*evals[9])(va_list args, t_conv *conv),
			t_conv *conv)
{
	char	*i;

	i = ft_strchr(CONVS, conv->conv);
	if (!i)
		return ;
	evals[(int) (i - (char *) CONVS)](args, conv);
}
