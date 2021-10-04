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

#include "ft_files.h"

int	ft_get_file_size(char *file_name)
{
	int		fd;
	int		rp;
	char	buff[BUFF_SIZE];
	int		size;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	size = 0;
	rp = read(fd, buff, BUFF_SIZE);
	while (rp > 0)
	{
		size += rp;
		rp = read(fd, buff, BUFF_SIZE);
	}
	close(fd);
	return (size);
}

int	ft_print_file(char *file_name, int offset,
	t_bool is_header, t_bool is_new_line)
{
	int		fd;
	char	tmp;
	int		rp;
	char	buff[BUFF_SIZE];

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (is_header)
		ft_put_header(file_name, is_new_line);
	while (--offset >= 0)
		read(fd, &tmp, 1);
	rp = read(fd, buff, BUFF_SIZE);
	while (rp > 0)
	{
		ft_putstrn(buff, rp);
		rp = read(fd, buff, BUFF_SIZE);
	}
	close(fd);
	return (rp);
}

char	*ft_read_stdin(void)
{
	int		rp;
	char	*output;
	char	buff[BUFF_SIZE + 1];

	output = (char *) malloc(sizeof(char));
	if (output == NULL)
		return (NULL);
	output[0] = '\0';
	rp = read(0, buff, BUFF_SIZE);
	while (rp > 0 && output != NULL)
	{
		buff[rp] = '\0';
		output = ft_strappend(output, buff);
		rp = read(0, buff, BUFF_SIZE);
	}
	if (rp < 0 || output == NULL)
		return (NULL);
	return (output);
}
