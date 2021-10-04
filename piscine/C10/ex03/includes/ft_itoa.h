/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_H
# define FT_ITOA_H

# include "ft_base.h"
# include "ft_atoi.h"
# include "ft_string.h"
# include "ft_string2.h"

void	ft_itoa_rev_inplace(int nbr, char *base, char *dest);
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);
char	*ft_itoa_base(int nbr, char *base_to);

#endif