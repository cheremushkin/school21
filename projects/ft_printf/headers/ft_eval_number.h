/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval_number.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 18:45:05 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:20:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EVAL_NUMBER_H
# define FT_EVAL_NUMBER_H

# include "libft.h"
# include "ft_conv.h"
# include "ft_strs_join.h"

typedef struct s_number
{
	unsigned long long	u_num;
	int					sign;
}	t_number;

void	ft_process_number_(t_number *n, long long num);
int		ft_add_precision_(t_conv *conv);
int		ft_set_int_prefix_(t_conv *conv, t_number n);
int		ft_set_hex_prefix_(t_conv *conv, int flag, char c);
int		ft_set_shift_(t_conv *conv);

#endif