#include <stdio.h>

void	test(int nb)
{
	printf("%d, %d\n", nb, ft_find_next_prime(nb));
}

int	main(void)
{
	test(-3);
	test(0);
	test(1);
	test(13);
	test(15);
	test(18);
	test(13245);
	test(2147483646);
	test(2147483647);
	return (0);
}