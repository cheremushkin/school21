/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversions.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:45:05 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:20:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CONVERSIONS_H
# define FT_CONVERSIONS_H

# include <stdlib.h>
# include "libft.h"

# define CONVERSIONS	"cspdiuxX%"
# define OPTIONS		"#+- .0"

typedef struct s_conversion
{
	char	*output;
	char	*end;
	size_t	len;
	char	conversion;
}	t_conversion;

int				ft_it_conversion(char c);
t_conversion	*ft_parse_conversion(char *str);

#endif
