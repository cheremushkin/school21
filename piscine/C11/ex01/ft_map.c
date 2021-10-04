/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 00:14:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 21:25:02 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*output;

	output = (int *) malloc(sizeof(int) * length);
	if (output == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		output[i] = f(tab[i]);
		i++;
	}
	return (output);
}
