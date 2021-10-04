/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 02:35:15 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/04 06:25:42 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
int	is_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	to_lower(char *c)
{
	int	shift;

	shift = 'a' - 'A';
	if (*c >= 'A' && *c <= 'Z')
		*c += shift;
}

void	to_upper(char *c)
{
	int	shift;

	shift = 'A' - 'a';
	if (*c >= 'a' && *c <= 'z')
		*c += shift;
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in;

	in = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (in)
		{
			if (!is_numeric(str[i]) && !is_alpha(str[i]))
				in = 0;
			else
				to_lower(str + i);
		}
		else
		{
			if (is_numeric(str[i]) || is_alpha(str[i]))
			{
				to_upper(str + i);
				in = 1;
			}
		}
		i++;
	}
	return (str);
}
