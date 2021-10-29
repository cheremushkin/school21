/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:54:57 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/05 00:02:56 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strndup_(char **dst, const char *src, long int n)
{
	*dst = (char *) malloc(sizeof(char) * (n + 1));
	if (!*dst)
		return (1);
	ft_memcpy(*dst, src, n);
	*(*dst + n) = 0;
	return (0);
}

static int	ft_count_words(const char *str, char c)
{
	int	n_words;
	int	in_word;

	in_word = 0;
	n_words = 0;
	while (*str)
	{
		if (in_word && *str == c)
			in_word = 0;
		else if (!in_word && *str != c)
		{
			in_word = 1;
			n_words += 1;
		}
		str++;
	}
	return (n_words);
}

static int	ft_populate_(const char *str, char c, char **strs)
{
	int		in_word;
	int		n_words;
	char	*start;

	in_word = 0;
	n_words = 0;
	while (*str)
	{
		if (in_word && *str == c)
		{
			in_word = 0;
			if (ft_strndup_(strs + n_words - 1, start, str - start))
				return (1);
		}
		else if (!in_word && *str != c)
		{
			in_word = 1;
			start = (char *) str;
			n_words += 1;
		}
		str++;
	}
	if (in_word && ft_strndup_(strs + n_words - 1, start, str - start))
		return (1);
	return (0);
}

static void	ft_free_strs(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char	**ft_split(char const *str, char c)
{
	int		n_words;
	char	**strs;

	n_words = ft_count_words(str, c);
	strs = (char **) ft_calloc(n_words + 1, sizeof(char *));
	if (!strs || ft_populate_(str, c, strs))
	{
		ft_free_strs(strs);
		return (NULL);
	}
	return (strs);
}
