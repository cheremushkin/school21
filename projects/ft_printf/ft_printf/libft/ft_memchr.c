/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 20:54:36 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/04 21:08:21 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*p;

	p = NULL;
	while (n--)
	{
		if (*((unsigned char *) s) == (unsigned char) c)
		{
			p = (void *) s;
			break ;
		}
		s++;
	}
	return (p);
}
