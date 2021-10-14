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

typedef	struct s_number
{
	unsigned int	u_num;
	int 			sign;
}	t_number;


void	ft_process_number_(t_number *n, int num)
{
	if (num >= 0)
	{
		n->u_num = num;
		n->sign = 1;
	}
	else
	{
		n->u_num = -num;
		n->sign = -1;
	}
}

char	*ft_strs_join(int n, ...)
{
	int		i;
	va_list	args;
	char	*str;
	char	*tmp;
	char	*out;

	va_start(args, n);
	out = ft_calloc(1, sizeof(char));
	if (!out)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str = va_arg(args, char *);
		if (str)
		{
			tmp = ft_strjoin(out, str);
			free(out);
			free(str);
			out = tmp;
		}
		i++;
	}
	return (out);
}

int	ft_eval_char(va_list args, t_conv *conv)
{
	// int		width;
	// char	*output;
	
	// width = FT_MAX(conv->width, 1);
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
	// conv->len = width;
	return (0);
}

int	ft_add_precision_(t_conv *conv)
{
	int		str_len;
	int		len;
	char	*tmp;

	str_len = ft_strlen(conv->out->c);
	len = FT_MAX(conv->precision - str_len, 0) + str_len;
	if (len == str_len)
		return (0);
	if (ft_malloc_((void **) &tmp, sizeof(char) * (len + 1)))
		return (1);
	ft_memset(tmp, '0', len - str_len);
	ft_strlcpy(tmp + len - str_len, conv->out->c, str_len + 1);
	free(conv->out->c);
	conv->out->c = tmp;
	conv->out->c_len = len;
	return (0);
}

int ft_set_prefix_(t_conv *conv, t_number n)
{
	if (ft_calloc_((void **) &(conv->out->p), 3, sizeof(char)))
		return (1);
	if (n.sign == -1)
	{
		conv->out->p[0] = '-';
		conv->out->p_len = 1;
	}
	else if (conv->flags->plus)
	{
		conv->out->p[0] = '+';
		conv->out->p_len = 1;
	}
	return (0);
}

int ft_set_shift_(t_conv *conv)
{
	t_output	*out;
	t_flags		*flags;
	int			w;

	out = conv->out;
	flags = conv->flags;
	w = conv->width;
	out->s_len = FT_MAX(FT_MAX(w, out->c_len + out->p_len) - (out->c_len + out->p_len), 0);
	if (ft_calloc_((void **) &(out->s), sizeof(char), out->s_len + 1))
		return (1);
	if (flags->zero && !flags->minus && conv->precision == -1)
		ft_memset(out->s, '0', out->s_len);
	else
		ft_memset(out->s, ' ', out->s_len);
	return (0);
}

int	ft_eval_int(va_list args, t_conv *conv)
{
	t_number	n;

	conv->out = (t_output *) malloc(sizeof(t_output));

	ft_process_number_(&n, va_arg(args, int));
	conv->out->c = ft_itoa(n.u_num);
	conv->out->c_len = ft_strlen(conv->out->c);
	if (!conv->out->c
		|| ft_add_precision_(conv)
		|| ft_set_prefix_(conv, n)
		|| ft_set_shift_(conv))
		return (1);
	if (conv->flags->minus)
		conv->out->str = ft_strs_join(3, conv->out->p, conv->out->c, conv->out->s);
	else
		conv->out->str = ft_strs_join(3, conv->out->s, conv->out->p, conv->out->c);
	conv->out->len = conv->out->p_len + conv->out->c_len + conv->out->s_len;
	return (0);
}

int	ft_eval_uint(va_list args, t_conv *conv)
{
	// TODO fix
	// int i = va_arg(args, unsigned int);
	// conv->output = ft_itoa((unsigned int) i);
	// conv->len = ft_strlen(conv->output);
	return (0);
}

int	ft_eval_string(va_list args, t_conv *conv)
{
	// conv->output = va_arg(args, char *);
	// conv->len = ft_strlen(conv->output);
	return (0);
}

int	ft_eval_percent(va_list args, t_conv *conv)
{
	// (void) args;
	// conv->output = ft_strdup("%");
	// conv->len = 1;
	return (0);
}