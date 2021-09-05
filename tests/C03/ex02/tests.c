#include <stdio.h>
#include <string.h>

void	test(char *dest_str, char *src, unsigned int size)
{
	char	dest[size];
	char	ft_dest[size];
	
	strcpy(dest, dest_str);
	strcpy(ft_dest, dest_str);
	
	strcat(dest, src);
	ft_strcat(ft_dest, src);

	printf("%d\n", strcmp(ft_dest, dest));
}

int	main(void)
{
	test("Hello", " world!", 13);
	test("Hello", " world!", 20);
	test("Hello", " w", 13);
	test("", "Hello world!", 15);
	
	return (0);
}
