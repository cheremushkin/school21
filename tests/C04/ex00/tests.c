#include <stdio.h>
#include <string.h>

void	test(char *str)
{
	printf("%d\n", ft_strlen(str) == (int) strlen(str));
}

int	main(void)
{
	test("Hello");
	test("");
	test("\n5a1");
	return (0);
}