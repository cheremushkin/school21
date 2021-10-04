/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:14:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:48 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*ar;

	if (min >= max)
		return (NULL);
	ar = (int *) malloc(sizeof(int) * (max - min));
	if (ar == NULL)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		ar[i] = min + i;
		i++;
	}
	return (ar);
}
