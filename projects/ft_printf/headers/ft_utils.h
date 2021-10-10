/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:38:17 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 04:02:15 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_structs.h"

size_t			ft_strlen(const char *s);
char			*ft_strchr(const char *s, int c);
void			ft_printf_push(t_printf *printf, t_printf_elem *elem);
t_printf_elem	*ft_init_printf_elem(char *start, size_t len, t_specs *specs);
//char			*ft_parse_specs(const char *str);
void			ft_print_printf(char *str, t_printf *printf);

#endif
