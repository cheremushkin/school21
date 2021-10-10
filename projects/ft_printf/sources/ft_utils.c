/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 03:41:35 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/10 04:10:54 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = NULL;
	while (*s)
	{
		if (*s == (char) c)
		{
			p = (char *) s;
			break ;
		}
		s++;
	}
	if (*s == (char) c)
		p = (char *) s;
	return (p);
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

t_printf_elem	*ft_init_printf_elem(char *start, size_t len, t_specs *specs)
{
	t_printf_elem	*elem;

	elem = (t_printf_elem *) malloc(sizeof(t_printf_elem));
	elem->start = start;
	elem->len = len;
	elem->specs = specs;
	elem->next = NULL;
	return (elem);
}

//char	*ft_parse_specs(const char *str)
//{
//	return ((char *) str + 1);
//}

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