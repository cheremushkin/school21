/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:16:46 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_MAP_H
# define FT_PARSE_MAP_H

# include <stdlib.h>
# include "ft_solve_map.h"
# include "ft_legend.h"
# include "ft_params.h"
# include "ft_string.h"
# include "ft_puts.h"
# include "ft_dp.h"

int	ft_parse_first_line(int fd, t_map *map);
int	ft_parse_other_lines(int fd, t_map *map);
int	ft_parse_map(int fd, t_map *map);

#endif