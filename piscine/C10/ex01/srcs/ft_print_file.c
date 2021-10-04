/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print_file.h"

int	ft_print_file(int fd)
{
	char	buff[BUFF_SIZE];
	int		rp;

	rp = read(fd, buff, BUFF_SIZE);
	while (rp > 0)
	{
		write(1, buff, rp);
		rp = read(fd, buff, BUFF_SIZE);
	}
	return (rp);
}
