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

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

# define CONVS		"cspdiuxX%"

typedef struct s_flags
{
	int	minus;
	int	plus;
	int	zero;
	int hash;
	int	space;
}	t_flags;

t_flags *ft_parse_flags(char *str, int *i);
int	    ft_parse_n(char *str, int *i);
int	    ft_parse_width(char *str, int *i);
int     ft_parse_precision(char *str, int *i);
int		ft_is_conv(char c);

#endif
