/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_params.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:16:43 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARAMS_H
# define FT_PARAMS_H

# include <stdlib.h>
# include "ft_types.h"

int		ft_check_map_line(char *str, t_params *params);
char	ft_int_to_char(int	n, t_params *params);
int		ft_char_to_int(char c, t_params *params);
int		*ft_str_to_int(char *str, t_params *params);
int		ft_check_params(t_params *params);

#endif