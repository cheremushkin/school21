#include <stdio.h>
#include <string.h>

int	sgn(int result)
{
	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;
	return (result);
}

void	test(char *s1, char *s2)
{
	printf("%d\n", sgn(strcmp(s1, s2)) == sgn(ft_strcmp(s1, s2)));
}

int	main(void)
{
	test("Equal strings", "Equal strings");
	test("Str1ng is bigger", "Str1ng is smaller");
	test("Str1ng is Bigger", "Str1ng is bigger");
	test("", "");
	test("Str1ng is bigger", "Str1ng is");
	test("Str1ng is smaller", "Str1ng is smaller?");
}
