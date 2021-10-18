/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval_string.h"

static int	ft_adjust_precision_(t_conv *conv)
{
	int	str_len;
	int	len;

	str_len = (int) ft_strlen(conv->out.c);
	if (conv->precision == -1)
		len = str_len;
	else
		len = ft_min(conv->precision, str_len);
	conv->out.c = ft_substr(conv->out.c, 0, len);
	if (!conv->out.c)
		return (1);
	conv->out.c_len = len;
	return (0);
}

static int	ft_set_string_shift_(t_conv *conv)
{
	conv->out.s_len = ft_max(
			ft_max(conv->width, conv->out.c_len) - conv->out.c_len,
			0);
	if (ft_malloc_((void **) &(conv->out.s),
			sizeof(char) * (conv->out.s_len + 1)))
		return (1);
	ft_memset(conv->out.s, ' ', conv->out.s_len);
	conv->out.s[conv->out.s_len] = 0;
	return (0);
}

int	ft_eval_string(va_list args, t_conv *conv)
{
	conv->out.c = va_arg(args, char *);
	if (!conv->out.c)
		conv->out.c = "(null)";
	conv->out.c_len = (int) ft_strlen(conv->out.c);
	if (ft_adjust_precision_(conv) || ft_set_string_shift_(conv))
		return (1);
	if (conv->flags.minus)
		conv->out.str = ft_strs_join(2, conv->out.c, conv->out.s);
	else
		conv->out.str = ft_strs_join(2, conv->out.s, conv->out.c);
	conv->out.len = conv->out.c_len + conv->out.s_len;
	return (0);
}
