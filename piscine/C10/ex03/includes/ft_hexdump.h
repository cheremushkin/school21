/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEXDUMP_H
# define FT_HEXDUMP_H

# define LINE_LEN 16
# define ADDR_LEN 8

# include <stdlib.h>
# include <libgen.h>
# include "ft_read.h"
# include "ft_dumps.h"
# include "ft_string.h"
# include "ft_boolean.h"
# include "ft_print_error.h"

t_bool	ft_hexdump_decision(char *prev, char *curr, t_bool *is_asterix);
int		ft_hexdump_content(char *content, t_bool option);
int		ft_hexdump_files(int n_files, char **file_names,
			t_bool option, char *bin_name);
int		ft_hexdump_stdin(t_bool option, char *bin_name);
void	ft_hexdump(int argc, char **argv, char *bin_name);

#endif