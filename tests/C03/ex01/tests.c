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

void	test(char *s1, char *s2, unsigned int n)
{
	printf("%d\n", sgn(strncmp(s1, s2, n)) == sgn(ft_strncmp(s1, s2, n)));
}


int	main(void)
{
	test("Equal strings", "Equal strings", 5);
	test("Str1ng is Bigger", "Str1ng is bigger", 10);
	test("Str1ng is bigger", "Str1ng is biGger", 14);
	test("", "", 1);
	test("Str1ng is bigger", "Str1ng is", 100);
	test("Str1ng", "Str1ng is smaller?", 15);
	test("String", "Str1ng is smaller?", 15);
	test("Atring", "Str1ng?", 0);
	test("Str1ng is Bigger", "Str1ng is_bigger", 10);
	return (0);
}
