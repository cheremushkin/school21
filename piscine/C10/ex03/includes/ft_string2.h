/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string2.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.school-2>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 02:15:06 by lteresia          #+#    #+#             */
/*   Updated: 2021/09/11 02:15:09 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING2_H
# define FT_STRING2_H

# include <stdlib.h>
# include "ft_string.h"

int		ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strrev(char *str);
char	*ft_strdup(char *src);
char	*ft_strappend(char *dest, char *src);
char	*ft_strappend_free(char *dest, char *src);

#endif