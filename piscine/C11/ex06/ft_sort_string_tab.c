/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 19:39:34 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 21:58:54 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	ft_tablen(char **tab)
{
	int	len;

	len = 0;
	while (*tab != (void *) 0)
	{
		len++;
		tab++;
	}
	return (len);
}

void	ft_bubble_sort(char **tab, int n)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (ft_strcmp(tab[j + 1], tab[j]) < 0)
			{
				tmp = tab[j + 1];
				tab[j + 1] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	tab_len;

	tab_len = ft_tablen(tab);
	ft_bubble_sort(tab, tab_len);
}
