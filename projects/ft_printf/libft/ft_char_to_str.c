/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_to_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 22:05:16 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 00:24:02 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_char_to_str(const char c)
{
    char    *str;

    str = (char *) malloc(sizeof(char) * 2);
    str[0] = c;
    str[1] = 0;
    return (str);
}
