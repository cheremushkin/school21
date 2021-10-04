/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 11:12:08 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/08 11:12:11 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{	
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

void	ft_rev_params(int argc, char *argv[])
{
	argc--;
	while (argc > 0)
	{
		ft_putstr(argv[argc--]);
		ft_putchar('\n');
	}
}

int	main(int argc, char *argv[])
{
	ft_rev_params(argc, argv);
	return (0);
}
