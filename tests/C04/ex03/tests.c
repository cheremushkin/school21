#include <stdio.h>

void	test(char *str)
{
	printf("%d\n", ft_atoi(str));
}

int	main(void)
{
	test(" -+--12.34ab567");
	test("\t -+12.34ab567");
	test(" --");
	test("");
	test("\r --++--00010 1");
	test("\v --++--000.10 1");
	return (0);
}
