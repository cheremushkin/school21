/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:16:53 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SOLVE_MAP_H
# define FT_SOLVE_MAP_H

# include <unistd.h>
# include "ft_dp.h"
# include "ft_utils.h"
# include "ft_types.h"
# include "ft_string.h"
# include "ft_parse_map.h"

int		ft_solve_map(int fd);
t_map	*ft_create_map(void);
void	ft_free_map(t_map *map);
void	ft_insert_solution(t_map *map);

#endif