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

int	ft_print_offset_error(char *arg, char *bin_name)
{
	ft_putstr_error(bin_name);
	ft_putstr_error(": illegal offset -- ");
	ft_putstr_error(arg);
	ft_putstr_error("\n");
	return (-1);
}

int	ft_print_option_error(char *option, char *bin_name)
{
	ft_putstr_error(bin_name);
	ft_putstr_error(": option requires an argument -- ");
	ft_putstr_error(option);
	ft_putstr_error("\n");
	ft_putstr_error("usage: ");
	ft_putstr_error(bin_name);
	ft_putstr_error(" [-c #] [file ...]\n");
	return (-1);
}
