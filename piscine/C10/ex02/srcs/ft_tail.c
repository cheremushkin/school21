/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	ft_tail_file(int n_files, char **file_names, int offset, char *bin_name)
{
	int		i;
	int		file_size;
	t_bool	is_header;
	t_bool	is_new_line;

	is_header = FALSE;
	if (n_files > 1)
		is_header = TRUE;
	i = 0;
	while (i < n_files)
	{
		is_new_line = TRUE;
		if (!i)
			is_new_line = FALSE;
		file_size = ft_get_file_size(file_names[i]);
		if (file_size == -1 && errno == 21)
			ft_put_header(file_names[i], is_new_line);
		else if (file_size == -1)
			ft_print_error(file_names[i], bin_name);
		else
			ft_print_file(file_names[i], file_size - offset,
				is_header, is_new_line);
		i++;
	}
}

void	ft_tail_stdin(int offset, char *bin_name)
{
	char	*input;

	input = ft_read_stdin();
	if (input == NULL)
	{
		ft_print_error("", bin_name);
		return ;
	}
	if (ft_strlen(input) < offset)
		offset = ft_strlen(input);
	ft_putstr(input + ft_strlen(input) - offset);
}

void	ft_tail(int argc, char **argv, char *bin_name)
{
	int	offset;
	int	arg_offset;

	offset = ft_get_offset(argc, argv, &arg_offset, bin_name);
	if (offset == -1)
		return ;
	if (argc - arg_offset == 0)
		ft_tail_stdin(offset, bin_name);
	else if (argc - arg_offset > 0)
		ft_tail_file(argc - arg_offset, argv + arg_offset, offset, bin_name);
}
