/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dumps.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DUMPS_H
# define FT_DUMPS_H

# include "ft_math.h"
# include "ft_base.h"
# include "ft_puts.h"
# include "ft_itoa.h"
# include "ft_puts2.h"
# include "ft_hexdump.h"
# include "ft_boolean.h"

void	ft_hexdump_addr(int addr);
void	ft_hexdump_fill_zero(int start, t_bool option);
void	ft_hexdump_content_line(char *line, int len, t_bool option);
void	ft_hexdump_line(char *content, int addr, t_bool option);
void	ft_dump_content_line(char *line, int len);

#endif