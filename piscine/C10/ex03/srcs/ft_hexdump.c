/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 16:10:46 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/01 16:30:50 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

t_bool	ft_hexdump_decision(char *prev, char *curr, t_bool *is_asterix)
{
	if (ft_strncmp(prev, curr, LINE_LEN) == 0 && !*is_asterix)
	{
		*is_asterix = TRUE;
		ft_putstr("*\n");
	}
	else if (ft_strncmp(prev, curr, LINE_LEN) != 0)
	{
		*is_asterix = FALSE;
		return (TRUE);
	}
	return (FALSE);
}	

int	ft_hexdump_content(char *content, t_bool option)
{
	int		addr;
	int		content_len;
	t_bool	is_asterix;

	addr = 0;
	content_len = ft_strlen(content);
	is_asterix = FALSE;
	if (!content_len)
		return (1);
	while (addr < content_len)
	{
		if ((addr >= 16 && ft_hexdump_decision(content + addr - LINE_LEN,
					content + addr, &is_asterix)) || addr < 16)
			ft_hexdump_line(content, addr, option);
		addr += LINE_LEN;
	}
	if (addr >= content_len)
		ft_hexdump_line(content, content_len, option);
	return (1);
}

int	ft_hexdump_files(int n_files, char **file_names,
	t_bool option, char *bin_name)
{
	char	*content;

	content = (char *) malloc(sizeof(char));
	if (content == NULL)
		return (ft_print_error(bin_name, bin_name));
	content[0] = '\0';
	content = ft_read_files(n_files, file_names, content, bin_name);
	if (ft_strlen(content) == 0 && errno)
		ft_print_descriptor_error(file_names[n_files - 1], bin_name);
	return (ft_hexdump_content(content, option));
}

int	ft_hexdump_stdin(t_bool option, char *bin_name)
{
	char	*content;

	content = ft_read_stdin();
	if (content == NULL)
		return (ft_print_error(bin_name, bin_name));
	return (ft_hexdump_content(content, option));
}

void	ft_hexdump(int argc, char **argv, char *bin_name)
{
	t_bool	option;

	option = FALSE;
	if (argc > 0 && ft_strcmp(argv[0], "-C") == 0)
		option = TRUE;
	if (option && argc > 1)
		ft_hexdump_files(argc - 1, argv + 1, option, bin_name);
	if (!option && argc > 0)
		ft_hexdump_files(argc, argv, option, bin_name);
	if ((option && argc == 1) || (!option && argc == 0))
		ft_hexdump_stdin(option, bin_name);
}
