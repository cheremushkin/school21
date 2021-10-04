/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dp.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:16:29 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DP_H
# define FT_DP_H

# include "ft_utils.h"
# include "ft_types.h"
# include "ft_params.h"

int			ft_do_dp(t_map *map);
int			**ft_init_dp(t_map *map);
void		ft_calculate_dp(t_map *map, int **dp);
void		ft_search_dp(int **dp, t_params *params, t_sq *square);
t_sq		*ft_create_sq(void);

#endif