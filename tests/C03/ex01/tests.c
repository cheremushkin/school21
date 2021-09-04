#include <stdio.h>
#include <string.h>

void	printf_result(int result)
{
	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;
	printf("%d\n", result);
}


int	main(void)
{
	printf_result(ft_strncmp("Equal strings", "Equal strings", 5));
	printf_result(ft_strncmp("Str1ng is Bigger", "Str1ng is bigger", 10));
	printf_result(ft_strncmp("Str1ng is bigger", "Str1ng is biGger", 14));
	printf_result(ft_strncmp("", "", 1));
	printf_result(ft_strncmp("Str1ng is bigger", "Str1ng is", 100));
	printf_result(ft_strncmp("Str1ng", "Str1ng is smaller?", 15));
	printf_result(ft_strncmp("String", "Str1ng is smaller?", 15));
	printf_result(ft_strncmp("Atring", "Str1ng?", 0));
	printf_result(ft_strncmp("Str1ng is Bigger", "Str1ng is_bigger", 10));	
}
