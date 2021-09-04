#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "strIng";
	char	s3[] = "$#2a%";
	char	s4[] = "_";
	char	s5[] = "";

	printf("%d\n%d\n%d\n%d\n%d", ft_str_is_alpha(s1), ft_str_is_alpha(s2), ft_str_is_alpha(s3), ft_str_is_alpha(s4), ft_str_is_alpha(s5));
	
	return (0);
}
