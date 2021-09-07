#include <stdio.h>

void	test(int nb)
{
	printf("%d, %d\n", nb, ft_is_prime(nb));
}

int	main(void)
{
	for (int i = -1; i < 6; i++)
		test(i);
	test(16);
	test(17);
	test(18);
	test(19);
	test(20);
	test(21);
	test(2147483646);
	test(2147483647);
	return (0);
}