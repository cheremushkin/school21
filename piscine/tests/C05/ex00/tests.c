#include <stdio.h>

void	test(int nb)
{
	printf("%d\n", ft_iterative_factorial(nb));
}

int	main(void)
{
	for (int i = -1; i < 13; i++)
		test(i);
	return (0);
}