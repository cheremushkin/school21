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

# define CONVS		"cspdiuxX%"
# define OPTIONS	"#+- .0"

typedef struct s_conv
{
	char	*output;
	char	*end;
	size_t	len;
	char	conv;
}	t_conv;

int		ft_is_conv(char c);
t_conv	*ft_parse_conv(char *str);
void	ft_eval_conv(va_list args,
			void (*evals[9])(va_list args, t_conv *conv),
			t_conv *conv);

#endif
