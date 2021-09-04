#include <stdio.h>

int main(void)
{
	char	s1[] = "String1";
	char	s2[] = "$ab^Q";
	char	s3[] = "";

	s2[1] = 127;

	printf("%d\n%d\n%d", ft_str_is_printable(s1), ft_str_is_printable(s2), ft_str_is_printable(s3));
	
	return (0);
}
