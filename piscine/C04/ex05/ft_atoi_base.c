/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 19:24:33 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/06 19:24:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	ft_is_space(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

unsigned int	ft_check_base(char *base)
{
	int				i;
	int				hash[255];
	unsigned int	base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	i = 0;
	while (i < 255)
		hash[i++] = 0;
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| ft_is_space(base[i]) || hash[(int) base[i]]
			|| base[i] < 32 || base[i] > 126)
			return (0);
		hash[(int) base[i]] = 1;
		i++;
	}
	return (base_len);
}

int	ft_find_digit_pos(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str, char *base)
{
	int				i;
	int				n;
	int				sign;
	unsigned int	base_len;

	base_len = ft_check_base(base);
	if (!base_len)
		return (0);
	i = 0;
	n = 0;
	sign = 1;
	while (ft_is_space(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign *= -1;
	}
	while (ft_find_digit_pos(*str, base) != -1)
		n = n * base_len + ft_find_digit_pos(*str++, base);
	return (sign * n);
}
