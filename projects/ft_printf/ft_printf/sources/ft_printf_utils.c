/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:41:35 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 20:48:41 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_utils.h"

t_printf	*ft_init_printf(void)
{
	t_printf	*printf;

	printf = (t_printf *) malloc(sizeof(t_printf));
	printf->head = NULL;
	printf->tail = NULL;
	printf->size = 0;
	printf->len = 0;
	ft_init_evals(printf);
	return (printf);
}

void	ft_printf_push(t_printf *printf, t_printf_elem *elem)
{
	if (!printf->size)
	{
		printf->head = elem;
		printf->tail = elem;
	}
	else
	{
		printf->tail->next = elem;
		printf->tail = elem;
	}
	printf->size++;
	printf->len += elem->len;
}

t_printf_elem	*ft_init_printf_elem(char *start, size_t len, t_conversion *conversion)
{
	t_printf_elem	*elem;

	elem = (t_printf_elem *) malloc(sizeof(t_printf_elem));
	elem->start = start;
	elem->len = len;
	elem->specs = conversion;
	elem->next = NULL;
	return (elem);
}

void	ft_print_printf(char *str, t_printf *printf)
{
	t_printf_elem	*elem;

	elem = printf->head;
	while (elem)
	{
		if (elem->start)
			write(1, elem->start, elem->len);
		else
			write(1, elem->specs->output, elem->len);
		elem = elem->next;
	}
}

void	ft_free_printf(t_printf *printf)
{
	free(printf);
}
