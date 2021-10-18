/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_hex.h"

static int	ft_eval_number(t_number *n, t_conv *conv, char *base)
{
	conv->out.c = ft_uitoa_base(n->u_num, base);
	if (!conv->out.c)
		return (1);
	conv->out.c_len = (int) ft_strlen(conv->out.c);
	if (ft_add_precision_(conv)
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

int	ft_eval_hex(va_list args, t_conv *conv)
{
	char		*base;
	t_number	n;

	if (conv->code == 'X')
		base = FT_HEXADECIMAL_UPPER;
	else
		base = FT_HEXADECIMAL_LOWER;
	ft_process_number_(&n, (long long) va_arg(args, unsigned int));
	if (ft_set_hex_prefix_(conv, conv->flags.hash && n.u_num > 0, conv->code))
		return (1);
	return (ft_eval_number(&n, conv, base));
}

int	ft_eval_pointer(va_list args, t_conv *conv)
{
	t_number	n;

	n.u_num = (unsigned long long) va_arg(args, void *);
	n.sign = 1;
	if (ft_set_hex_prefix_(conv, 1, 'x'))
		return (1);
	ft_eval_number(&n, conv, FT_HEXADECIMAL_LOWER);
	return (0);
}
