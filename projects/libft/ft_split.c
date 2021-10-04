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

static char	*ft_strndup(const char *src, int n)
{
	char	*dst;
	int		i;

	dst = (char *) malloc(sizeof(char) * (n + 1));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dst[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	dst[n] = '\0';
	return (dst);
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

static void	ft_populate(const char *str, char c, char **strs)
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
			strs[n_words - 1] = ft_strndup(start, str - start);
		}
		else if (!in_word && *str != c)
		{
			in_word = 1;
			start = (char *) str;
			n_words += 1;
		}
		str++;
	}
	if (in_word)
		strs[n_words - 1] = ft_strndup(start, str - start);
}

char	**ft_split(char const *str, char c)
{
	int		n_words;
	char	**strs;

	if (str == NULL)
		return (NULL);
	n_words = ft_count_words(str, c);
	strs = (char **) malloc(sizeof(char *) * (n_words + 1));
	if (strs == NULL)
		return (NULL);
	ft_populate(str, c, strs);
	strs[n_words] = NULL;
	return (strs);
}
