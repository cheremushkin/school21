/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 19:54:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/11 22:32:56 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_eval.h"

void	ft_eval_conv(va_list args,
			int (*evals[9])(va_list args, t_conv *conv),
			t_conv *conv)
{
	char	*i;

	i = ft_strchr(CONVS, conv->code);
	if (!i)
		return ;
	evals[(int) (i - (char *) CONVS)](args, conv);
}
