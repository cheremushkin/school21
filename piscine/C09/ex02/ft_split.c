/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:14:47 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/09 15:14:48 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		i;

	dest = (char *) malloc(sizeof(char) * (n + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i++;
	}
	dest[n] = '\0';
	return (dest);
}

int	ft_count_words(char *str, int *hash)
{
	int	n_words;
	int	in_word;

	in_word = 0;
	n_words = 0;
	while (*str)
	{
		if (in_word)
		{
			if (hash[(int) *str])
				in_word = 0;
		}
		else
		{
			if (!hash[(int) *str])
			{
				in_word = 1;
				n_words += 1;
			}
		}
		str++;
	}
	return (n_words);
}

void	ft_populate(char *str, int *hash, char **strs)
{
	int		in_word;
	int		n_words;
	char	*start;

	in_word = 0;
	n_words = 0;
	while (*str)
	{
		if (in_word && hash[(int) *str])
		{
			in_word = 0;
			strs[n_words - 1] = ft_strndup(start, str - start);
		}
		else if (!in_word && !hash[(int) *str])
		{
			in_word = 1;
			start = str;
			n_words += 1;
		}
		str++;
	}
	if (in_word)
		strs[n_words - 1] = ft_strndup(start, str - start);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		n_words;
	int		hash[255];
	char	**strs;

	i = 0;
	while (i < 255)
		hash[i++] = 0;
	while (*charset)
		hash[(int) *charset++] = 1;
	n_words = ft_count_words(str, hash);
	strs = (char **) malloc(sizeof(char *) * (n_words + 1));
	if (strs == NULL)
		return (NULL);
	ft_populate(str, hash, strs);
	strs[n_words] = NULL;
	return (strs);
}
