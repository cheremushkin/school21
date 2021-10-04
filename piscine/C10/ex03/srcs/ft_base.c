/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_base.h"

unsigned int	ft_check_base(char *base)
{
	int				i;
	int				hash[255];
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (i < 255)
		hash[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (ft_is_sign(base[i]) || hash[(int) base[i]]
			|| base[i] < 32 || base[i] > 126)
			return (0);
		hash[(int) base[i]] = 1;
		i++;
	}
	return (base_len);
}
