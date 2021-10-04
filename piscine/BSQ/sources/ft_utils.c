/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:26:44 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:17:47 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

int	**ft_create_2d_int_zero_array(int height, int width)
{
	int	**array;
	int	i;
	int	j;

	array = (int **) malloc(sizeof(int *) * height);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		array[i] = (int *) malloc(sizeof(int) * width);
		if (array[i] == NULL)
			return (NULL);
		j = 0;
		while (j < width)
			array[i][j++] = 0;
		i++;
	}
	return (array);
}

char	**ft_create_2d_char_null_array(int height)
{
	char	**array;
	int		i;

	array = (char **) malloc(sizeof(char *) * height);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < height)
		array[i++] = NULL;
	return (array);
}

void	ft_free_2d_int_array(int **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (array[i] != NULL)
			free(array[i++]);
	}
	free(array);
}

void	ft_free_2d_char_array(char **array, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		if (array[i] != NULL)
			free(array[i]);
		i++;
	}
	free(array);
}

int	ft_min(int n, int m)
{
	if (n > m)
		return (m);
	return (n);
}
