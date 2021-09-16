#include <stdio.h>
#include "ft_list.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

t_list	*ft_list_last_(t_list *begin_list)
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
	last = ft_list_last_(*begin_list);
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

int	main()
{
	t_list 	*start1, *start2;
	start1 = ft_create_elem(strdup("0"));
	start2 = NULL;
	ft_sorted_list_merge(&start1, start2, strcmp);
	ft_list_push_back(&start1, strdup("2"));
	ft_list_push_back(&start1, strdup("4"));
	ft_list_push_back(&start1, strdup("6"));
	print_list(start1);
	start2 = ft_create_elem(strdup("1"));
	ft_list_push_back(&start2, strdup("3"));
	ft_list_push_back(&start2, strdup("5"));
	ft_list_push_back(&start2, strdup("7"));
	ft_sorted_list_merge(&start1, start2, strcmp);
	print_list(start1);
	return (0);
}
