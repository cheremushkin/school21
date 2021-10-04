/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 15:33:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/07 15:33:08 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	f;
	int	i;

	if (nb < 0)
		return (0);
	f = 1;
	i = 1;
	while (i <= nb)
		f *= i++;
	return (f);
}
