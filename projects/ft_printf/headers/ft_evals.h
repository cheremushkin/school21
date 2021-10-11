/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evals.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:31 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 23:59:32 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVALS_H
# define FT_EVALS_H

# include <stdarg.h>
# include "libft.h"
# include "ft_convs.h"

void	ft_eval_char(va_list args, t_conv *conv);
void    ft_eval_int(va_list args, t_conv *conv);
void    ft_eval_uint(va_list args, t_conv *conv);
void    ft_eval_string(va_list args, t_conv *conv);
void    ft_eval_percent(va_list args, t_conv *conv);

#endif
