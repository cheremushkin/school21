#include <stdio.h>

void	test(int nb)
{
	printf("%d\n", ft_sqrt(nb));
}

int	main(void)
{
	test(-2);
	test(0);
	test(4);
	test(256);
	test(2147395600);
	test(2147483647);
	return (0);
}