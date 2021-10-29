/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lteresia <lteresia@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:42:49 by lteresia          #+#    #+#             */
/*   Updated: 2021/10/06 15:57:01 by lteresia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# define FT_ATOI_POS_MAX 2147483647
# define FT_ATOI_NEG_MAX 2147483648

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
int		ft_malloc_(void **p, size_t size);
void	*ft_calloc(size_t count, size_t size);
int		ft_calloc_(void **p, size_t count, size_t size);
char	*ft_strrev(char *str);
char	*ft_strdup(const char *src);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	**ft_split(char const *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
char	*ft_itoa(int n);
char	*ft_itoa_base(long long n, const char *base);
char	*ft_uitoa_base(unsigned long long n, const char *base);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
int		ft_abs(int n);

t_list	*ft_list_create_elem(void *content);
int		ft_list_size(t_list *head);
t_list	*ft_list_last(t_list *head);
t_list	*ft_list_at(t_list *head, unsigned int n);
void	ft_list_push_front(t_list **head, t_list *new);
void	ft_list_push_back(t_list **head, t_list *new);
void	ft_list_delete_elem(t_list *elem, void (*del)(void *));
void	ft_list_delete(t_list **head, void (*del)(void *));
void	ft_list_foreach(t_list *head, void (*f)(void *));
t_list	*ft_list_map(t_list *head, void *(*f)(void *), void (*del)(void *));

#endif
