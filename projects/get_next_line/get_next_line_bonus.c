/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:50:10 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/08 22:04:31 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_create_zero_str(char **str)
{
	if (*str)
		return (0);
	*str = (char *) malloc(sizeof(char));
	if (!*str)
		return (1);
	**str = 0;
	return (0);
}

char	*ft_extract_line(char **str, char *pos)
{
	char	*line;
	char	*tmp;

	if (!pos)
	{
		if (ft_strlen(*str))
			line = ft_substr(*str, 0, ft_strlen(*str));
		else
			line = NULL;
		free(*str);
		*str = NULL;
		return (line);
	}
	line = ft_substr(*str, 0, pos - *str + 1);
	if (*pos)
		tmp = ft_substr(pos + 1, 0, ft_strlen(pos + 1));
	else
		tmp = NULL;
	free(*str);
	*str = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*memory[FD_SIZE];
	char		buf[BUFFER_SIZE + 1];
	char		*tmp;
	int			n_bytes;
	char		*pos;

	if (fd < 0 || fd >= FD_SIZE || read(fd, 0, 0) < 0
		|| ft_create_zero_str(memory + fd))
		return (NULL);
	pos = ft_strchr(memory[fd], '\n');
	while (!pos)
	{
		n_bytes = read(fd, buf, BUFFER_SIZE);
		if (n_bytes < 0)
			return (NULL);
		if (!n_bytes)
			break ;
		buf[n_bytes] = 0;
		if (ft_strjoin_(memory[fd], buf, &tmp))
			return (NULL);
		free(memory[fd]);
		memory[fd] = tmp;
		pos = ft_strchr(memory[fd], '\n');
	}
	return (ft_extract_line(memory + fd, pos));
}
