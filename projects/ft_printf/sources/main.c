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
	printf("%llu\n\n", ULONG_MAX);
	// printf("%s\n", ft_itoa_base(-9223372036854775808, FT_BINARY));
	TEST("%p %p ", ULONG_MAX, -ULONG_MAX);
	printf("\n\n");
	return (0);
}
