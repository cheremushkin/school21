/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:13:23 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/15 22:02:17 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	ft_bubble_sort(char **tab, int n, int(*cmp)(char *, char *))
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
			if (cmp(tab[j + 1], tab[j]) < 0)
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

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	tab_len;

	tab_len = ft_tablen(tab);
	ft_bubble_sort(tab, tab_len, cmp);
}
