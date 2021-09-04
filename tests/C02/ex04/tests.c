#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "aqx";
	char	s3[] = "$#2a%";
	char	s4[] = "";

	printf("%d\n%d\n%d\n%d", ft_str_is_lowercase(s1), ft_str_is_lowercase(s2), ft_str_is_lowercase(s3), ft_str_is_lowercase(s4));
	
	return (0);
}
