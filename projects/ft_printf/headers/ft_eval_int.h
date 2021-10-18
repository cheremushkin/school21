/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:31 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_INT_H
# define FT_EVAL_INT_H

# include <stdarg.h>
# include "libft.h"
# include "ft_conv.h"
# include "ft_strs_join.h"
# include "ft_eval_number.h"

int	ft_eval_int(va_list args, t_conv *conv);
int	ft_eval_uint(va_list args, t_conv *conv);

#endif
