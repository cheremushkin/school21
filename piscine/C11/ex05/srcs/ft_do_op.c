/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 21:55:16 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_do_op.h"

int	get_op_id(char *op)
{
	if (ft_strcmp(op, "+") == 0)
		return (0);
	if (ft_strcmp(op, "-") == 0)
		return (1);
	if (ft_strcmp(op, "*") == 0)
		return (2);
	if (ft_strcmp(op, "/") == 0)
		return (3);
	if (ft_strcmp(op, "%") == 0)
		return (4);
	return (-1);
}

void	ft_do_op(int argc, char **argv)
{
	int		n;
	int		m;
	int		op_id;
	void	(*operations[5])(int, int);

	if (argc != 3)
		return ;
	operations[0] = &ft_putsum;
	operations[1] = &ft_putsubstr;
	operations[2] = &ft_putmult;
	operations[3] = &ft_putdiv;
	operations[4] = &ft_putmod;
	op_id = get_op_id(argv[1]);
	if (op_id == -1)
		return (ft_putstr("0\n"));
	n = ft_atoi(argv[0]);
	m = ft_atoi(argv[2]);
	(*operations[op_id])(n, m);
}
