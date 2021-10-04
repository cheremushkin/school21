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
	printf("null\n");
}

int	main()
{
	t_list	*start;
	char	*strs[3];
	strs[0] = "first";
	strs[1] = "second";
	strs[2] = "third";
	start = ft_list_push_strs(3, strs);
	print_list(start);
	char	**strs2;
	strs2 = NULL;
	start = ft_list_push_strs(0, strs2);
	print_list(start);
	return (0);
}
