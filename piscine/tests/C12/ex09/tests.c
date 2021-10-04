#include <stdio.h>
#include "ft_list.h"

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

void	print_data(void	*data)
{
	printf("%s ", (char *) data);
}

int	main()
{
	t_list *start;
	start = NULL;
	ft_list_foreach(start, print_data);
	printf("%s", "\n");
	start = ft_create_elem("1");
	ft_list_foreach(start, print_data);
	printf("%s", "\n");
	ft_list_push_back(&start, "2");
	ft_list_push_back(&start, "3");
	ft_list_push_back(&start, "4");
	ft_list_foreach(start, print_data);
	return (0);
}
