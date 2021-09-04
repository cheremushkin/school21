#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "ADZ";
	char	s3[] = "$#2a%";
	char	s4[] = "";

	printf("%d\n%d\n%d\n%d", ft_str_is_uppercase(s1), ft_str_is_uppercase(s2), ft_str_is_uppercase(s3), ft_str_is_uppercase(s4));
	
	return (0);
}
