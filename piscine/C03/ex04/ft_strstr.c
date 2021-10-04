/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 16:28:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/05 20:24:39 by lteresia         ###   ########.fr       */
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

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	if (!n)
		return (0);
	while (*s1 && (*s1 == *s2) && (n-- > 1))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	find_len;

	find_len = ft_strlen(to_find);
	if (!find_len)
		return (str);
	i = 0;
	while (*(str + i) != '\0')
	{
		if (!ft_strncmp(str + i, to_find, find_len))
			return (str + i);
		i++;
	}
	return ((void *)0);
}
