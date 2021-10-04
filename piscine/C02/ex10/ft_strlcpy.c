/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 03:47:53 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/04 06:22:55 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{	
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	while (i < size - 1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			return (src_len);
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}
