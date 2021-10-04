/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_offset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_offset.h"

int	ft_get_offset(int argc, char **argv, int *args_offset, char *bin_name)
{
	char	*offset_str;

	if (ft_strncmp(argv[0], "-c", 2))
		return (-1);
	if (ft_strcmp(argv[0], "-c") == 0)
	{
		if (argc == 1)
			return (ft_print_option_error("c", bin_name));
		offset_str = argv[1];
		*args_offset = 2;
	}
	else
	{
		offset_str = argv[0] + 2;
		*args_offset = 1;
	}
	if (!ft_str_is_numeric(offset_str))
		return (ft_print_offset_error(offset_str, bin_name));
	return (ft_atoi(offset_str));
}
