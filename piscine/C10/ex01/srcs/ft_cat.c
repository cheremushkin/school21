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

#include "ft_cat.h"

int	ft_cat(int n_files, char **file_names, char *bin_name)
{
	int	i;
	int	fd;

	if (n_files == 0 && ft_cat_stdin())
		return (ft_print_error("", bin_name));
	i = 0;
	while (i < n_files)
	{
		if (ft_strcmp(file_names[i], "-") == 0)
		{
			if (ft_cat_stdin())
				return (ft_print_error("", bin_name));
		}
		else
		{
			fd = open(file_names[i], O_RDONLY);
			if (fd == -1 || ft_print_file(fd))
				return (ft_print_error(file_names[i], bin_name));
			close(fd);
		}
		i++;
	}
	return (0);
}

int	ft_cat_stdin(void)
{
	return (ft_print_file(0));
}
