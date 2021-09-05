#include <stdio.h>
#include <string.h>

void	test(char *str, char *to_find)
{
	printf("%d\n", ft_strstr(str, to_find) == strstr(str, to_find));
}

int	main(void)
{
	char	str[] = "This is string";
	char	to_find1[] = "is";
	char	to_find2[] = "is ";
	char	to_find3[] = " is";
	char	to_find4[] = "g";
	char	to_find5[] = "This is string";
	char	to_find6[] = "This is string!";
	char	to_find7[] = "where?";
	char	to_find8[] = "";
	test(str, to_find1);
	test(str, to_find2);
	test(str, to_find3);
	test(str, to_find4);
	test(str, to_find5);
	test(str, to_find6);
	test(str, to_find7);
	test(str, to_find8);
	test("", "42");
	return (0);
}
