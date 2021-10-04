/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:12:08 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/08 11:12:11 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{	
	int	i;

	i = 0;
	while (*(str + i))
		write(1, str + i++, 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	ft_bubble_sort(int n, char *array[])
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strcmp(array[j + 1], array[j]) < 0)
			{
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_params(int argc, char *argv[])
{
	int	i;

	if (argc > 1)
	{
		ft_bubble_sort(argc - 1, argv + 1);
		i = 1;
		while (i < argc)
		{
			ft_putstr(argv[i++]);
			ft_putstr("\n");
		}
	}
}

int	main(int argc, char *argv[])
{
	ft_sort_params(argc, argv);
	return (0);
}
