/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_display_file.h"

void	ft_putstr_error(char *str)
{	
	while (*str)
		write(2, str++, 1);
}

int	ft_print_error(int code)
{
	if (code == 1)
		ft_putstr_error("File name missing.\n");
	else if (code == 2)
		ft_putstr_error("Too many arguments.\n");
	else if (code == 3)
		ft_putstr_error("Cannot read file.\n");
	return (0);
}
