/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:33:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/07 15:33:08 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int *ar, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = ar[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

void	ft_clean_columns(int *columns, int x)
{
	while (x < 10)
		columns[x++] = -1;
}

int	ft_is_position_free(int x, int y, int *columns)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if ((y - (x - i) >= 0 && columns[i] == y - (x - i))
			|| (y + (x - i) >= 0 && columns[i] == y + (x - i))
			|| columns[i] == y)
			return (0);
		i++;
	}
	return (1);
}

int	ft_put_queen(int x, int *columns, int n_solutions)
{
	int	j;

	j = 0;
	while (j < 10)
	{
		if (ft_is_position_free(x, j, columns))
		{
			columns[x] = j;
			if (x == 9)
			{
				ft_print_solution(columns, 10);
				n_solutions++;
			}
			else
				n_solutions = ft_put_queen(x + 1, columns, n_solutions);
			ft_clean_columns(columns, x);
		}
		j++;
	}
	return (n_solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	i;
	int	columns[10];
	int	n_solutions;

	i = 0;
	while (i < 10)
		columns[i++] = -1;
	n_solutions = ft_put_queen(0, columns, 0);
	return (n_solutions);
}
