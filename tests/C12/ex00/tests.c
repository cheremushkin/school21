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
	t_list *elem;
	elem = ft_create_elem("first");
	print_list(elem);
	return (0);
}
