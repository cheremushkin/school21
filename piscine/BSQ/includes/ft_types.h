/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:16:59 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

typedef struct s_params
{
	int		m;
	int		n;
	char	empty;
	char	obstacle;
	char	full;
}	t_params;

typedef struct s_sq
{
	int	size;
	int	x;
	int	y;
}	t_sq;

typedef struct s_map
{
	char		**tab;
	t_params	*params;
	t_sq		*sq;
}	t_map;

#endif