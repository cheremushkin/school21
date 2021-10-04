/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTS_H
# define FT_PUTS_H

# include <unistd.h>
# include <errno.h>
# include <string.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putchar_error(char c);
void	ft_putstr_error(char *str);
void	ft_putnbr(int nb);

#endif