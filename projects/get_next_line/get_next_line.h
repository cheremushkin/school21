/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 21:46:38 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/08 21:46:45 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

# define FD_SIZE 127

char	*get_next_line(int fd);
int		ft_create_zero_str(char **str);
char	*ft_extract_line(char **str, char *pos);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strncpy(char *dst, const char *src, size_t n);
int		ft_strjoin_(char const *s1, char const *s2, char **dst);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
