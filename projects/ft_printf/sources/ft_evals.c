/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evals.h"
#include <stdio.h>

void	ft_eval_char(va_list args, t_conv *conv)
{
	int		width;
	char	*output;
	
	width = FT_MAX(conv->width, 1);
	output = (char *) malloc(sizeof(char) * (width + 1));
	if (conv->flags->zero)
		ft_memset(output, '0', width);
	else
		ft_memset(output, ' ', width);
	if (conv->flags->minus)
		output[0] = va_arg(args, int);
	else
		output[width - 1] = va_arg(args, int);
	conv->output = output;
	conv->len = width;
}

void	ft_eval_int(va_list args, t_conv *conv)
{
	int		n;
	char	*itoa;
	int		len;
	int		width;

	n = va_arg(args, int);
	itoa = ft_itoa(n);
	len = ft_strlen(itoa);
	width = FT_MAX(FT_MAX(conv->width, conv->precision), len);
	// if (n > 0 && conv->flags->plus)
	// 	width = FT_MAX(width, len + 1)
	// output = (char *) malloc(sizeof(char) * (width + 1));
	// if (conv->flags->zero)
	// 	ft_memset(output, '0', width);
	// else
	// 	ft_memset(output, ' ', width);
	// if (conv->flags->minus)
	// 	output[0] = va_arg(args, int);
	// else
	// 	output[width - 1] = va_arg(args, int);
	// conv->output = output;
	// 	conv->len = width;
	conv->output = itoa;
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