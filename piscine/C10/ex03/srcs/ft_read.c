/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_read.h"

char	*ft_memread(int fd)
{
	int		rp;
	char	*output;
	char	buff[BUFF_SIZE + 1];

	output = (char *) malloc(sizeof(char));
	if (output == NULL)
		return (NULL);
	output[0] = '\0';
	rp = read(fd, buff, BUFF_SIZE);
	while (rp > 0 && output != NULL)
	{
		buff[rp] = '\0';
		output = ft_strappend(output, buff);
		rp = read(fd, buff, BUFF_SIZE);
	}
	if (rp < 0 || output == NULL)
		return (NULL);
	return (output);
}

char	*ft_read_stdin(void)
{
	return (ft_memread(0));
}

char	*ft_read_file(char *file_name, char *bin_name)
{
	int		fd;
	char	*output;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
	{
		ft_print_error(file_name, bin_name);
		return (NULL);
	}
	output = ft_memread(fd);
	if (output == NULL || close(fd) == -1)
	{
		ft_print_error(file_name, bin_name);
		return (NULL);
	}
	return (output);
}

char	*ft_read_files(int n_files, char **file_names,
	char *content, char *bin_name)
{
	int		i;
	char	*file_content;

	i = 0;
	while (i < n_files)
	{
		file_content = ft_read_file(file_names[i], bin_name);
		if (file_content == NULL)
		{
			i++;
			continue ;
		}
		content = ft_strappend_free(content, file_content);
		if (content == NULL)
		{
			ft_print_error(file_names[i], bin_name);
			return (NULL);
		}		
		i++;
	}
	return (content);
}
