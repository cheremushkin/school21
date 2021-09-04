#include <stdio.h>

int main(void)
{
	char	s1[] = "quiCK_+che2ck";
	char	s2[] = "ANOTHER^cHECK";
	char	s3[] = "_ 10_^b&*@#aB";
	char	s4[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";

	printf("%s\n%s\n%s\n%s", ft_strcapitalize(s1), ft_strcapitalize(s2), ft_strcapitalize(s3), ft_strcapitalize(s4));
	return (0);
}
