#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "aqx";
	char	s3[] = "$#2z%";

	printf("%s\n%s\n%s", ft_strupcase(s1), ft_strupcase(s2), ft_strupcase(s3));
	
	return (0);
}
