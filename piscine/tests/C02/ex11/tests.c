#include <stdio.h>

int main(void)
{
	char	str1[] = "Coucou\ntu vas bien ?";
	char	str2[] = "More\f escape \rsymbols\v";

	ft_putstr_non_printable(str1);
	ft_putchar('\n');
	ft_putstr_non_printable(str2);
	return (0);
}
