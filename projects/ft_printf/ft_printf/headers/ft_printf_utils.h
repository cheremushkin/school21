/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:38:17 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:51:05 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_UTILS_H
# define FT_PRINTF_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "ft_eval.h"
# include "ft_conversions.h"

typedef struct s_printf_elem
{
	char					*start;
	size_t 					len;
	t_conversion			*specs;
	struct s_printf_elem	*next;
}	t_printf_elem;

typedef struct s_printf
{
	va_list			args;
	char			*(*evals[9])(struct s_printf *);
	t_printf_elem	*head;
	t_printf_elem	*tail;
	size_t			size;
	size_t			len;
}	t_printf;

t_printf		*ft_init_printf(void);
void			ft_printf_push(t_printf *printf, t_printf_elem *elem);
t_printf_elem	*ft_init_printf_elem(char *start, size_t len, t_conversion *specs);
void			ft_print_printf(char *str, t_printf *printf);
void			ft_free_printf(t_printf *printf);

#endif