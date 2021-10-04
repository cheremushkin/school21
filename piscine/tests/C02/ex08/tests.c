#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "Aqx";
	char	s3[] = "$#2Z%";

	printf("%s\n%s\n%s", ft_strlowcase(s1), ft_strlowcase(s2), ft_strlowcase(s3));
	
	return (0);
}
