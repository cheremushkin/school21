/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <libgen.h>
# include "ft_puts.h"
# include "ft_puts2.h"
# include "ft_atoi.h"
# include "ft_files.h"
# include "ft_string.h"
# include "ft_boolean.h"
# include "ft_offset.h"
# include "ft_print_error.h"

void	ft_tail(int n_files, char **file_names, char *bin_name);
void	ft_tail_file(int n_files, char **file_names,
			int offset, char *bin_name);
void	ft_tail_stdin(int offset, char *bin_name);

#endif