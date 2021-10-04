/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:14:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:48 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int				ft_atoi_base(char *str, char *base);
unsigned int	ft_check_base(char *base);
unsigned int	ft_strlen(char *str);

char	*ft_strrev(char *str)
{
	int		i;
	int		str_len;
	char	tmp;

	str_len = ft_strlen(str);
	i = 0;
	while (i < str_len - i)
	{
		tmp = str[i];
		str[i] = str[str_len - i - 1];
		str[str_len - i - 1] = tmp;
		i++;
	}
	return (str);
}

void	ft_itoa_rev_inplace(int nbr, char *base, char *dest)
{
	int				i;
	int				sign;
	unsigned int	n;
	unsigned int	base_len;

	base_len = ft_check_base(base);
	sign = 1;
	i = 0;
	if (nbr < 0)
	{
		sign = -1;
		n = -1 * nbr;
	}
	else
		n = nbr;
	if (n == 0)
		dest[i++] = base[0];
	while (n != 0)
	{
		dest[i++] = base[n % base_len];
		n /= base_len;
	}
	if (sign == -1)
		dest[i++] = '-';
	dest[i] = '\0';
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (dest == NULL)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		n;
	char	converted[33];

	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	n = ft_atoi_base(nbr, base_from);
	ft_itoa_rev_inplace(n, base_to, converted);
	return (ft_strrev(ft_strdup(converted)));
}
