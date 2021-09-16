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

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	prev = (void *) 0;
	current = *begin_list;
	next = (void *) 0;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

int	main()
{
	t_list 	*start;
	
	start = NULL;
	ft_list_reverse_fun(&start);
	print_list(start);
	start = ft_create_elem(strdup("1"));
	ft_list_reverse_fun(&start);
	print_list(start);
	ft_list_push_back(&start, strdup("0"));
	ft_list_reverse_fun(&start);
	print_list(start);
	ft_list_push_back(&start, strdup("2"));
	ft_list_push_back(&start, strdup("3"));
	ft_list_push_back(&start, strdup("4"));
	ft_list_reverse_fun(&start);
	print_list(start);
	return (0);
}
