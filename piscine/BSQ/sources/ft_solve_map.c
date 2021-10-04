/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:49:24 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:17:39 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_solve_map.h"

void	ft_print_map(t_map *map)
{
	int		i;
	char	*output;
	int		output_len;

	i = 0;
	output_len = 0;
	while (i < map->params->m)
	{
		output_len += map->params->n;
		i++;
	}
	output_len += map->params->m;
	output = ft_strnjoin_by_lb(map->tab, map->params->m,
			map->params->n, output_len);
	write(1, output, output_len);
	free(output);
}

void	ft_insert_solution(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->sq->size)
	{
		j = 0;
		while (j < map->sq->size)
			map->tab[map->sq->y + i][map->sq->x + j++] = map->params->full;
		i++;
	}
}

t_map	*ft_create_map(void)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	map->params = NULL;
	map->sq = NULL;
	map->tab = NULL;
	return (map);
}

void	ft_free_map(t_map *map)
{
	if (map->tab != NULL)
		ft_free_2d_char_array(map->tab, map->params->m);
	if (map->sq != NULL)
		free(map->params);
	if (map->params != NULL)
		free(map->sq);
	free(map);
}

int	ft_solve_map(int fd)
{
	t_map		*map;

	map = ft_create_map();
	if (ft_parse_map(fd, map) || ft_do_dp(map))
	{
		ft_free_map(map);
		return (1);
	}
	ft_insert_solution(map);
	ft_print_map(map);
	ft_free_map(map);
	return (0);
}
