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

#include "ft_display_file.h"

int	main(int argc, char **argv)
{
	int	fd;
	int	code;

	if (argc == 1)
		return (ft_print_error(1));
	else if (argc > 2)
		return (ft_print_error(2));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_print_error(3));
	code = ft_print_file(fd);
	close(fd);
	return (code);
}
