/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_READ_H
# define FT_READ_H

# include <stddef.h>
# include <fcntl.h>
# include <unistd.h>
# include "ft_puts.h"
# include "ft_puts2.h"
# include "ft_boolean.h"
# include "ft_string.h"
# include "ft_string2.h"
# include "ft_print_error.h"

# define BUFF_SIZE 19999

char	*ft_memread(int fd);
char	*ft_read_stdin(void);
char	*ft_read_file(char *file_name, char *bin_name);
char	*ft_read_files(int n_files, char **file_names,
			char *content, char *bin_name);

#endif