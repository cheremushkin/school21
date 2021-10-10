/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:59:19 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 04:10:32 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRUCTS_H
#define FT_STRUCTS_H

typedef struct s_specs
{
	char	*output;
	char	*end;
	int		len;
	int		minus;
	int		plus;
	int		space;
	int		zero;
	int		hash;
	int		width;
	int		precision;
}	t_specs;

typedef struct s_printf_elem
{
	char					*start;
	size_t 					len;
	t_specs					*specs;
	struct s_printf_elem	*next;
}	t_printf_elem;

typedef struct s_printf
{
	t_printf_elem	*head;
	t_printf_elem	*tail;
	size_t			size;
	size_t			len;
}	t_printf;

#endif
