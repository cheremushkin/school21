/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 17:07:34 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 21:47:51 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	sorted_asc;
	int	sorted_des;

	i = 0;
	sorted_asc = 1;
	sorted_des = 1;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			sorted_asc = 0;
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sorted_des = 0;
		i++;
	}
	if (sorted_asc || sorted_des)
		return (1);
	return (0);
}
