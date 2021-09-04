#include <stdio.h>

int	main(void)
{
	printf("%d\n", ft_strcmp("Equal strings", "Equal strings"));
	printf("%d\n", ft_strcmp("Str1ng is bigger", "Str1ng is smaller") > 0 ? 1 : -1);
	printf("%d\n", ft_strcmp("Str1ng is Bigger", "Str1ng is bigger") > 0 ? 1 : -1);
	printf("%d\n", ft_strcmp("", ""));
	printf("%d\n", ft_strcmp("Str1ng is bigger", "Str1ng is") > 0 ? 1 : -1);
	printf("%d\n", ft_strcmp("Str1ng is smaller", "Str1ng is smaller?") > 0 ? 1 : -1);
}
