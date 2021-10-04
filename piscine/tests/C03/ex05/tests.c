#include <stdio.h>
#include <string.h>

void	test(char *dest_str, char *src, unsigned int size)
{
	char	dest[size];
	char	ft_dest[size];
	int	diff;	
	
	strcpy(dest, dest_str);
	strcpy(ft_dest, dest_str);

	diff = ft_strlcat(ft_dest, src, size) == strlcat(dest, src, size);
	printf("%d, %d\n", diff, strcmp(ft_dest, dest));
}

int	main(void)
{
	test("Hello", " world!", 13);
	test("Hello", " world!", 20);
	test("Hello", " w", 13);
	test("", "Hello world!", 15);
	test("Hello", ", append very long string", 15);
	test("Hello", " world!", 3);
	
	return (0);
}
