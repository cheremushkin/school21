/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 21:45:11 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/12 17:41:34 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	printf("\n\n");
	printf("%+3.0d|\n", 12);
	ft_printf("%+3.0d|\n", 12);
	printf("\n\n");
	return (0);
}
