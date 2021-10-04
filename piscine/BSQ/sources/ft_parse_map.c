/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 20:31:57 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:17:24 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parse_map.h"

int	ft_parse_first_line(int fd, t_map *map)
{
	char	*line;
	char	buf;
	int		rp;

	line = (char *) malloc(sizeof(char));
	if (line == NULL)
		exit(0);
	line[0] = '\0';
	rp = read(fd, &buf, 1);
	while (rp > 0 && buf != '\n')
	{
		line = ft_strappend_char(line, &buf);
		if (line == NULL)
			return (1);
		rp = read(fd, &buf, 1);
	}
	map->params->n = ft_strlen(line);
	if (buf != '\n' || !ft_check_map_line(line, map->params))
		return (1);
	map->tab[0] = line;
	return (0);
}

int	ft_parse_other_lines(int fd, t_map *map)
{
	int		i;
	int		rp;
	char	*line;

	line = (char *) malloc(sizeof(char) * (map->params->n + 1));
	if (line == NULL)
		return (1);
	i = 1;
	while (i < map->params->m)
	{
		rp = read(fd, line, map->params->n + 1);
		if (rp < map->params->n + 1 || line[map->params->n] != '\n'
			|| !ft_check_map_line(line, map->params))
			return (1);
		map->tab[i] = ft_strndup(line, map->params->n);
		if (map->tab[i] == NULL)
			exit(0);
		i++;
	}
	if (read(fd, line, 1))
		return (1);
	free(line);
	return (0);
}

int	ft_parse_map(int fd, t_map *map)
{
	char	*legend;

	map->params = (t_params *) malloc(sizeof(t_params));
	if (map->params == NULL)
		exit(0);
	legend = ft_read_legend(fd);
	if (legend == NULL || ft_parse_legend(legend, map->params))
		return (ft_putstr_error("map error\n"));
	map->tab = ft_create_2d_char_null_array(map->params->m);
	if (map->tab == NULL
		|| ft_parse_first_line(fd, map)
		|| !ft_check_params(map->params)
		|| ft_parse_other_lines(fd, map))
		return (ft_putstr_error("map error\n"));
	return (0);
}
