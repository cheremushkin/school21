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

void	create_clear_list()
{
	t_list *start;
	start = ft_create_elem(strdup("0"));
	int m = 1;
	for (int j = 0; j < m; j++)
	{
		int n = 1000000;
		char	*s = (char *) malloc(sizeof(char) * n);
		for (int i = 0; i < n - 1; i++)
			s[i] = '1';
		s[n] = '\n';
		ft_list_push_back(&start, s);
	}
	ft_list_clear(start, free);
}

int	main()
{
	for (int i = 0; i < 5000; i++)
		create_clear_list();
	t_list *start;
	start = ft_create_elem(strdup("0"));
	ft_list_push_back(&start, strdup("1"));
	ft_list_push_back(&start, strdup("2"));
	ft_list_push_back(&start, strdup("3"));
	ft_list_clear(start->next->next, free);
	start->next->next = NULL;
	print_list(start);
	return (0);
}
