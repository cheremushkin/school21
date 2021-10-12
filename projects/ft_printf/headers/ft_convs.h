/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convs.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:45:05 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:20:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVS_H
# define FT_CONVS_H

# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"
# include "ft_parsers.h"

typedef struct s_conv
{
	char	*output;
	char	*end;
	size_t	len;
	char	code;

	t_flags	*flags;
	int		width;
	int		precision;
}	t_conv;

t_conv	*ft_parse(char *str);

#endif
