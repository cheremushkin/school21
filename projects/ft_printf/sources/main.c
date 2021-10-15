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
#include <limits.h>

#define TEST(...) \
    printf("system's: "); \
	printf("\n%d\n", printf(__VA_ARGS__)); \
	ft_printf("my      : "); \
	ft_printf("\n%d\n", ft_printf(__VA_ARGS__));

int	main(void)
{
	printf("\n\n");
//	printf("|%-5.1s|\n", "string");
	TEST("%s", "");
	TEST(" %s", "");
	TEST("%s ", "");
	TEST(" %s ", "");
	TEST(" %s ", "-");
	TEST(" %s %s ", "", "-");
	TEST(" %s %s ", " - ", "");
	TEST(" %s %s %s %s ", " - ", "", "4", "");
	TEST(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
	TEST(" NULL %s NULL ", NULL);
//    int j = ft_printf(" %c %c %c |\n", '0', 0, '1');
//    getchar();
//	ft_printf("%-14d\n", 0);
	printf("\n\n");
//	printf("real: %d, my: %d\n", i, j);
	return (0);
}
