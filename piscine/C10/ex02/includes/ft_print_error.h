/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_ERROR_H
# define FT_PRINT_ERROR_H

# include "ft_puts.h"

int	ft_print_error(char *file_name, char *bin_name);
int	ft_print_offset_error(char *arg, char *bin_name);
int	ft_print_option_error(char *option, char *bin_name);

#endif