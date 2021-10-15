/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_int.h"
#include <stdio.h>

int	ft_eval_number(t_number *n, t_conv *conv)
{
	conv->out.c = ft_itoa(n->u_num);
	if (!conv->out.c)
		return (1);
	conv->out.c_len = ft_strlen(conv->out.c);
	if (ft_add_precision_(conv)
		|| ft_set_prefix_(conv, *n)
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

int	ft_eval_int(va_list args, t_conv *conv)
{
	t_number	n;

	ft_process_number_(&n, va_arg(args, int));
	return (ft_eval_number(&n, conv));
}

int	ft_eval_uint(va_list args, t_conv *conv)
{
	t_number	n;

	ft_process_number_(&n, va_arg(args, unsigned int));
	return (ft_eval_number(&n, conv));
}

int ft_set_prefix_hex(t_conv *conv, int flag)
{
	if (ft_calloc_((void **) &(conv->out.p), 3, sizeof(char)))
		return (1);
	if (flag)
	{
		conv->out.p[0] = '0';
		conv->out.p[1] = conv->code;
		conv->out.p_len = 2;
	}
	return (0);
}

int	ft_eval_hex(va_list args, t_conv *conv)
{
	char		*base;
	t_number	n;

	if (conv->code == 'X')
		base = FT_HEXADECIMAL_UPPER;
	else if (conv->code == 'x')
		base = FT_HEXADECIMAL_LOWER;

	ft_process_number_(&n, va_arg(args, unsigned int));
	conv->out.c = ft_itoa_base(n.u_num, base);
	if (!conv->out.c)
		return (1);
	conv->out.c_len = ft_strlen(conv->out.c);
	if (ft_add_precision_(conv)
		|| ft_set_prefix_hex(conv, conv->flags.hash && n.u_num > 0)
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

int	ft_eval_pointer(va_list args, t_conv *conv)
{
	t_number	n;

	conv->code = 'x';
	conv->flags.hash = 1;
	n.u_num = (unsigned long long) va_arg(args, void *);
	n.sign = 1;
	conv->out.c = ft_uitoa_base(n.u_num, FT_HEXADECIMAL_LOWER);
	if (!conv->out.c)
		return (1);
	conv->out.c_len = ft_strlen(conv->out.c);
	if (ft_add_precision_(conv)
		|| ft_set_prefix_hex(conv, 1)
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
