/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts2.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUTS2_H
# define FT_PUTS2_H

# include <unistd.h>
# include "ft_puts.h"
# include "ft_boolean.h"
# include "ft_base.h"

void	ft_putstrn(char *str, int n);
void	ft_put_header(char *name, t_bool is_new_line);
void	ft_putnbr_base(int nbr, char *base);
void	ft_putnbr(int nbr);

#endif