/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:56:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:12:00 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval.h"

void	ft_init_evals(t_printf *printf)
{
	printf->evals[0] = ft_eval_int;
	printf->evals[1] = ft_eval_string;
}