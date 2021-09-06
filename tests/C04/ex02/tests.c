#include <unistd.h>

void	test(int i)
{
	char c = '\n';
	ft_putnbr(i);
	write(1, &c, 1);
}

int	main(void)
{
	test(0);
	test(1);
	test(-1);
	test(10);
	test(-10);
	test(2147483647);
	test(-2147483648);
	return (0);
}
