/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 00:04:16 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evals.h"
#include <stdio.h>

void	ft_eval_char(va_list args, t_conv *conv)
{
	conv->output = ft_char_to_str(va_arg(args, int));
	conv->len = 1;
}

void	ft_eval_int(va_list args, t_conv *conv)
{
	conv->output = ft_itoa(va_arg(args, int));
	conv->len = ft_strlen(conv->output);
}

void	ft_eval_uint(va_list args, t_conv *conv)
{
	// TODO fix
	int i = va_arg(args, unsigned int);
	conv->output = ft_itoa((unsigned int) i);
	conv->len = ft_strlen(conv->output);
}

void	ft_eval_string(va_list args, t_conv *conv)
{
	conv->output = va_arg(args, char *);
	conv->len = ft_strlen(conv->output);
}

void	ft_eval_percent(va_list args, t_conv *conv)
{
	(void) args;
	conv->output = ft_strdup("%");
	conv->len = 1;
}