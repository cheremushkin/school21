/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 02:59:40 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 15:58:23 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HANDLER_H
# define FT_HANDLER_H

# include <unistd.h>
# include "libft.h"
# include "ft_eval_int.h"
# include "ft_eval_hex.h"
# include "ft_eval_char.h"
# include "ft_eval_string.h"
# include "ft_eval_percent.h"
# include "ft_conv.h"

typedef struct s_handler
{
	va_list	args;
	int		len;
	int		(*evals[9])(va_list args, t_conv *conv);
}	t_handler;

void	ft_init_handler(t_handler *parser);
int		ft_handle_conv(t_handler *handler, t_conv *conv);
void	ft_print_handler(t_handler *parser, char *str, size_t len);

#endif