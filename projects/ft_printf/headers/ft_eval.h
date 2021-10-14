/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:31 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_H
# define FT_EVAL_H

# include <stdarg.h>
# include "ft_convs.h"

void	ft_eval_conv(va_list args,
			int (*evals[9])(va_list args, t_conv *conv),
			t_conv *conv);

#endif
