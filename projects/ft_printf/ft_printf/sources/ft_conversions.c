/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:54:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 19:55:13 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_conversions.h"

int	ft_it_conversion(char c)
{
	return ((int) (ft_strchr(CONVERSIONS, c) - (char *) 0));
}

t_conversion	*ft_parse_conversion(char *str)
{
	int	i;
	t_conversion	*specs;

	specs = (t_conversion *) malloc(sizeof(t_conversion));

	i = 0;
	while (!ft_it_conversion(str[i]))
		i++;
	specs->conversion = str[i];
	specs->len = 2;
	specs->end = str + i + 1;
	return (specs);
}