/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:16:36 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LEGEND_H
# define FT_LEGEND_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_is.h"
# include "ft_params.h"
# include "ft_string.h"

int		ft_parse_legend(char *legend, t_params *params);
char	*ft_read_legend(int	fd);

#endif