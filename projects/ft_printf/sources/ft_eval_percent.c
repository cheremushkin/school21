/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_percent.h"

static int	ft_set_percent_shift_(t_conv *conv)
{
	conv->out.s_len = ft_max(
			ft_max(conv->width, conv->out.c_len) - conv->out.c_len,
			0);
	if (ft_calloc_((void **) &(conv->out.s), sizeof(char), conv->out.s_len + 1))
		return (1);
	if (conv->flags.zero && !conv->flags.minus)
		ft_memset(conv->out.s, '0', conv->out.s_len);
	else
		ft_memset(conv->out.s, ' ', conv->out.s_len);
	return (0);
}

int	ft_eval_percent(va_list args, t_conv *conv)
{
	(void) args;
	conv->out.c = ft_strdup("%");
	if (!conv->out.c)
		return (1);
	conv->out.c_len = 1;
	if (ft_set_percent_shift_(conv))
		return (1);
	if (!conv->flags.minus)
		conv->out.str = ft_strs_join(3, conv->out.s, conv->out.p, conv->out.c);
	else
		conv->out.str = ft_strs_join(3, conv->out.p, conv->out.c, conv->out.s);
	conv->out.len = conv->out.p_len + conv->out.c_len + conv->out.s_len;
	return (0);
}
