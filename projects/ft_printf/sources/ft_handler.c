/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:41:35 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_handler.h"

void	ft_init_handler(t_handler *handler)
{
	handler->len = 0;
	handler->evals[0] = ft_eval_char;
	handler->evals[1] = ft_eval_string;
	handler->evals[2] = ft_eval_pointer;
	handler->evals[3] = ft_eval_int;
	handler->evals[4] = ft_eval_int;
	handler->evals[5] = ft_eval_uint;
	handler->evals[6] = ft_eval_hex;
	handler->evals[7] = ft_eval_hex;
	handler->evals[8] = ft_eval_percent;
}

int	ft_handle_conv(t_handler *handler, t_conv *conv)
{
	ft_bzero(&(conv->out), sizeof(t_output));
	return (handler->evals[conv->id](handler->args, conv));
}

void	ft_print_handler(t_handler *handler, char *str, size_t len)
{
	handler->len += write(1, str, len);
}
