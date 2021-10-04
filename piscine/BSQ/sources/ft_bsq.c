/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:59:28 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:17:06 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bsq.h"

int	ft_bsq(int n_args, char **args)
{
	int	fd;
	int	i;

	if (n_args == 0)
		ft_solve_map(0);
	i = 0;
	while (i < n_args)
	{
		fd = open(args[i], O_RDONLY);
		if (fd < 0)
			ft_putstr_error("map error\n");
		else
			ft_solve_map(fd);
		close(fd);
		if (i != n_args - 1)
			ft_putstr("\n");
		i++;
	}
	return (0);
}
