#include <stdio.h>

void	test(int index)
{
	printf("%d\n", ft_fibonacci(index));
}

int	main(void)
{
	for (int i = -1; i < 9; i++)
		test(i);
	return (0);
}