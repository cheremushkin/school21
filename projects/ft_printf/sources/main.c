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

// #define TEST(...) \
//     printf("system's: "); \
// 	printf(" | -> %d\n", printf(__VA_ARGS__)); \
// 	ft_printf("my      : "); \
// 	ft_printf(" | -> %d", ft_printf(__VA_ARGS__));

#include <stdlib.h>

int	main(void)
{
	printf(" | -> %d\n", printf("%100001.10d", 100));
	return (0);
}
