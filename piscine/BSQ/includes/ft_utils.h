/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:19:02 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>

int		**ft_create_2d_int_zero_array(int height, int width);
char	**ft_create_2d_char_null_array(int height);
void	ft_free_2d_int_array(int **array, int height);
void	ft_free_2d_char_array(char **array, int height);
int		ft_min(int n, int m);

#endif