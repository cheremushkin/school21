#include <stdio.h>

int main(void)
{
	char	src[] = "String1";
	char	dest[8];
	char	*output;
	
	output = ft_strcpy(dest, src);
	printf("%s, %s, %s\n", src, dest, output);
	
	return (0);
}
