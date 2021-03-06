/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:45:05 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:20:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSERS_H
# define FT_PARSERS_H

# include <limits.h>
# include "libft.h"

# define CONVERSIONS 	"\x63\x73\x70\x64\x69\x75\x78\x58\x25"
# define N_CONVERSIONS	9
// maximum width/precision that can be printed
# define FT_MAX_PRINT_N	1000000

typedef struct s_flags
{
	int	minus;
	int	plus;
	int	zero;
	int	hash;
	int	space;
}	t_flags;

t_flags	*ft_parse_flags(char *str, t_flags *flags, int *i);
int		ft_parse_n(char *str, int *i);
int		ft_parse_width(char *str, int *i);
int		ft_parse_precision(char *str, int *i);
int		ft_get_conversion_id(char c);

#endif
