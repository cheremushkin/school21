/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:45:05 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:20:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONV_H
# define FT_CONV_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_parsers.h"

typedef struct s_output
{
	char	*str;
	size_t	len;

	char	*p;
	size_t	p_len;

	char	*s;
	size_t	s_len;

	char	*c;
	size_t	c_len;
}	t_output;

typedef struct s_conv
{
	t_output	out;
	char		*end;
	char		code;

	t_flags		flags;
	int			width;
	int			precision;
}	t_conv;

void	ft_parse_conv(t_conv *conv, char *str);

#endif
