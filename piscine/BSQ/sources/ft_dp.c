/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:31:08 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:21:26 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_dp.h"

int	**ft_init_dp(t_map *map)
{
	int	**dp;
	int	i;
	int	j;

	dp = ft_create_2d_int_zero_array(map->params->m, map->params->n);
	if (dp == NULL)
		return (NULL);
	i = 0;
	while (i < map->params->m)
	{
		dp[i][0] = ft_char_to_int(map->tab[i][0], map->params);
		i++;
	}
	j = 0;
	while (j < map->params->n)
	{
		dp[0][j] = ft_char_to_int(map->tab[0][j], map->params);
		j++;
	}
	return (dp);
}

void	ft_calculate_dp(t_map *map, int **dp)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->params->m)
	{
		j = 1;
		while (j < map->params->n)
		{
			if (map->tab[i][j] == map->params->obstacle)
				dp[i][j] = 0;
			if (map->tab[i][j] == map->params->empty)
				dp[i][j] = 1 + ft_min(dp[i - 1][j - 1],
						ft_min(dp[i - 1][j], dp[i][j - 1]));
			j++;
		}
		i++;
	}
}

t_sq	*ft_create_sq(void)
{
	t_sq	*sq;

	sq = (t_sq *) malloc(sizeof(t_sq));
	if (sq == NULL)
		exit(0);
	sq->size = 0;
	sq->x = 0;
	sq->y = 0;
	return (sq);
}

void	ft_search_dp(int **dp, t_params *params, t_sq *sq)
{
	int	i;
	int	j;

	i = 0;
	while (i < params->m)
	{
		j = 0;
		while (j < params->n)
		{
			if (dp[i][j] > sq->size)
			{
				sq->size = dp[i][j];
				sq->x = j - dp[i][j] + 1;
				sq->y = i - dp[i][j] + 1;
			}
			j++;
		}
		i++;
	}
}

int	ft_do_dp(t_map *map)
{
	int	**dp;

	dp = ft_init_dp(map);
	if (dp == NULL)
		return (1);
	ft_calculate_dp(map, dp);
	map->sq = ft_create_sq();
	ft_search_dp(dp, map->params, map->sq);
	ft_free_2d_int_array(dp, map->params->m);
	return (0);
}
