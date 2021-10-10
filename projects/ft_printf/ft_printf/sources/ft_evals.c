/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_evals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:28:56 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 18:29:46 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_evals.h"

char	*ft_eval_int(t_printf *printf)
{
	return ft_itoa(va_arg(printf->args, int));
}

char	*ft_eval_string(t_printf *printf)
{
	return va_arg(printf->args, char *);
}

