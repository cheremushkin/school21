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

# include <unistd.h>
# include <string.h>
# include <errno.h>

void	ft_putchar_error(char c);
void	ft_putstr_error(char *str);
int		ft_print_error(char *file_name, char *bin_name);

#endif