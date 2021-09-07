#include <stdio.h>

void	test(int nb, int power)
{
	printf("%d\n", ft_recursive_power(nb, power));
}

int	main(void)
{
	test(0, 0);
	test(-2, 3);
	test(-2, -2);
	test(10, 0);
	test(10, 3);
	test(1, 1000);
	return (0);
}