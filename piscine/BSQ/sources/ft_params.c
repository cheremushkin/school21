/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:04:15 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:19:34 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_params.h"
#include "ft_puts.h"

int	ft_check_map_line(char *str, t_params *params)
{
	int	i;

	i = 0;
	while (i < params->n)
	{
		if (str[i] != params->empty && str[i] != params->obstacle)
			return (0);
		i++;
	}
	return (1);
}

char	ft_int_to_char(int	n, t_params *params)
{
	if (n == 0)
		return (params->obstacle);
	if (n == 1)
		return (params->empty);
	if (n == -1)
		return (params->full);
	return ('\0');
}

int	ft_char_to_int(char c, t_params *params)
{
	if (params->obstacle == c)
		return (0);
	if (params->empty == c)
		return (1);
	return (-1);
}

int	*ft_str_to_int(char *str, t_params *params)
{
	int	i;
	int	*array;

	array = (int *) malloc(sizeof(int) * params->n);
	if (array == NULL)
		return (NULL);
	i = 0;
	while (i < params->n)
	{
		array[i] = ft_char_to_int(str[i], params);
		if (array[i] == -1)
			return (NULL);
		i++;
	}
	return (array);
}

int	ft_check_params(t_params *params)
{
	if (params->empty == params->full
		|| params->empty == params->obstacle
		|| params->full == params->obstacle
		|| params->m == 0 || params->n == 0)
		return (0);
	return (1);
}
