/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                     :+:      :+:    :+:    */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_int.h"

static int	ft_eval_number(t_number *n, t_conv *conv)
{
	conv->out.c = ft_uitoa_base(n->u_num, FT_DECIMAL);
	if (!conv->out.c)
		return (1);
	conv->out.c_len = (int) ft_strlen(conv->out.c);
	if (ft_add_precision_(conv)
		|| ft_set_int_prefix_(conv, *n)
		|| ft_set_shift_(conv))
		return (1);
	if (!conv->flags.minus && conv->flags.zero)
		conv->out.str = ft_strs_join(3, conv->out.p, conv->out.s, conv->out.c);
	else if (conv->flags.minus)
		conv->out.str = ft_strs_join(3, conv->out.p, conv->out.c, conv->out.s);
	else
		conv->out.str = ft_strs_join(3, conv->out.s, conv->out.p, conv->out.c);
	conv->out.len = conv->out.p_len + conv->out.c_len + conv->out.s_len;
	return (0);
}

static void	ft_preprocess_flags_(t_conv *conv)
{
	if ((conv->flags.zero && conv->flags.minus)
		|| (conv->flags.zero && conv->precision != -1))
		conv->flags.zero = 0;
}

int	ft_eval_int(va_list args, t_conv *conv)
{
	t_number	n;

	ft_preprocess_flags_(conv);
	ft_process_number_(&n, va_arg(args, int));
	return (ft_eval_number(&n, conv));
}

int	ft_eval_uint(va_list args, t_conv *conv)
{
	t_number	n;

	ft_preprocess_flags_(conv);
	ft_process_number_(&n, va_arg(args, unsigned int));
	return (ft_eval_number(&n, conv));
}
