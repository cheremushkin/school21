/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_files.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILES_H
# define FT_FILES_H

# include <unistd.h>
# include <fcntl.h>
# include "ft_puts.h"
# include "ft_puts2.h"
# include "ft_string.h"
# include "ft_boolean.h"

# define BUFF_SIZE 19999

int		ft_get_file_size(char *file_name);
int		ft_print_file(char *file_name, int offset,
			t_bool is_header, t_bool is_new_line);
char	*ft_read_stdin(void);

#endif