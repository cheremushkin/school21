/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_legend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: MEGA_BRAINS (lteresia, smackere) < >       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:53:09 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/22 21:19:29 by MEGA_BRAINS      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_legend.h"
#include "ft_puts.h"

int	ft_parse_legend(char *legend, t_params *params)
{
	int			m;
	int			i;
	int			len;

	len = ft_strlen(legend);
	if (len < 4 || ft_is_str_printable(legend))
		return (1);
	params->full = legend[len - 1];
	params->obstacle = legend[len - 2];
	params->empty = legend[len - 3];
	m = 0;
	i = 0;
	while (i < len - 3)
	{
		if (!ft_is_digit(legend[i]))
			return (1);
		m = m * 10 + legend[i] - '0';
		i++;
	}
	params->m = m;
	free(legend);
	return (0);
}

char	*ft_read_legend(int	fd)
{
	char	*legend;
	char	buf;
	int		rp;

	legend = (char *) malloc(sizeof(char));
	if (legend == NULL)
		exit(0);
	legend[0] = '\0';
	rp = read(fd, &buf, 1);
	while (rp > 0 && buf != '\n')
	{
		legend = ft_strappend_char(legend, &buf);
		if (legend == NULL)
			exit(0);
		rp = read(fd, &buf, 1);
	}
	if (buf != '\n')
		return (NULL);
	return (legend);
}
