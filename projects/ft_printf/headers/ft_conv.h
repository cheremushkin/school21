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

# include <stdarg.h>
# include "libft.h"
# include "ft_parsers.h"

typedef struct s_output
{
	char	*str;
	int		len;

	char	*p;
	int		p_len;

	char	*s;
	int		s_len;

	char	*c;
	int		c_len;
}	t_output;

typedef struct s_conv
{
	t_output	out;
	char		*end;
	char		code;
	int			id;

	t_flags		flags;
	int			width;
	int			precision;
}	t_conv;

int	ft_parse_conv(t_conv *conv, char *str);

#endif
