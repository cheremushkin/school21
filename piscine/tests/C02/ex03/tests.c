#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "1234";
	char	s3[] = "$#2a%";
	char	s4[] = "";

	printf("%d\n%d\n%d\n%d", ft_str_is_numeric(s1), ft_str_is_numeric(s2), ft_str_is_numeric(s3), ft_str_is_numeric(s4));
	
	return (0);
}
