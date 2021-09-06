#include <stdio.h>

void	test(char *str, char *base)
{
	printf("%d\n", ft_atoi(str, base));
}

int main(void)
{
	test(" ---+--+1234ab567", "0123456789");
	test(" ---+--+1234ab567", "0123456789a");
	test(" \t--+--+1234ab567", "0123456789ab");
	test(" ---+--+1234ab567", "0123456789ab+");
	test(" ---+--+1234ab567", "0123456789ab0");
	test(" ---+--+1234ab567", "0");
	test(" ---+--+1234ab567", "ab");
	test(" ---+--+ab567ba", "ba");
	test(" ---+--+7776", "abcdefg");
	test(" ---+--+7776abc", "abcdefg");
	return (0);
}