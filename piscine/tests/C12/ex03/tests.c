#include <stdio.h>
#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (elem == (void *) 0)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
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
	t_list *start;
	start = ft_create_elem("third");
	print_list(ft_list_last(start));
	ft_list_push_front(&start, "second");
	ft_list_push_front(&start, "first");
	print_list(ft_list_last(start));
	return (0);
}
