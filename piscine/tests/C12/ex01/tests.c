#include <stdio.h>
#include "ft_list.h"

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
	printf("null");
}

int	main()
{
	t_list *start;
	start = ft_create_elem("third");
	ft_list_push_front(&start, "second");
	ft_list_push_front(&start, "first");
	print_list(start);
	return (0);
}
