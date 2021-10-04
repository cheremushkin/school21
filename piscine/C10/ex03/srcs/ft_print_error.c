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

#include "ft_print_error.h"

int	ft_print_error(char *file_name, char *bin_name)
{
	ft_putstr_error(bin_name);
	ft_putstr_error(": ");
	ft_putstr_error(file_name);
	ft_putstr_error(": ");
	ft_putstr_error(strerror(errno));
	ft_putchar_error('\n');
	return (errno);
}

int	ft_print_descriptor_error(char *arg, char *bin_name)
{
	ft_putstr_error(bin_name);
	ft_putstr_error(": ");
	ft_putstr_error(arg);
	ft_putstr_error(": ");
	ft_putstr_error("Bad file descriptor\n");
	return (-1);
}
