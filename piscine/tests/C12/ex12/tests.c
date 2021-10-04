#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*elem;

	elem = begin_list;
	while (elem->next)
		elem = elem->next;
	return (elem);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*new;

	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!*begin_list)
	{
		*begin_list = new;
		return ;
	}
	last = ft_list_last(*begin_list);
	last->next = new;
}

void	print_list(t_list *start)
{
	t_list *elem;
	int		i;

	i = 0;
	elem = start;
	while (elem)
	{
		printf("(%d) %s -> ", i, elem->data);
		elem = elem->next;
		i++;
	}
	printf("null\n");
}

char	*create_string(char c)
{
	int n = 10000;
	char	*s = (char *) malloc(sizeof(char) * n);
	for (int i = 0; i < n - 1; i++)
		s[i] = c;
	s[n] = '\n';
	return s;
}

void	create_clear_list()
{
	t_list *start;
	start = ft_create_elem(strdup("0"));
	int m = 1000;
	for (int j = 0; j < m; j++)
		ft_list_push_back(&start, create_string('1'));
	ft_list_remove_if(&start, create_string('1'), strcmp, free);
}

int	main()
{
	t_list *start;
	for (int i = 0; i < 500; i++)
		create_clear_list();
	printf("REMOVED\n");
	start = ft_create_elem(strdup("0"));
	ft_list_push_back(&start, strdup("1"));
	ft_list_push_back(&start, strdup("3"));
	ft_list_push_back(&start, strdup("2"));
	ft_list_push_back(&start, strdup("1"));
	ft_list_push_back(&start, strdup("1"));
	ft_list_remove_if(&start, "1", strcmp, free);
	print_list(start);
	ft_list_remove_if(&start, "0", strcmp, free);
	print_list(start);
	ft_list_remove_if(&start, "3", strcmp, free);
	print_list(start);
	ft_list_remove_if(&start, "2", strcmp, free);
	print_list(start);
	return (0);
}
