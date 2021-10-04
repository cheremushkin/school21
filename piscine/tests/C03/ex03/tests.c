#include <stdio.h>
#include <string.h>

int	sgn(int result)
{
	if (result > 0)
		result = 1;
	else if (result < 0)
		result = -1;
	return (result);
}

void	test(char *dest_str, char *src, unsigned int size)
{
	char	dest[size];
	char	ft_dest[size];
	
	strcpy(dest, dest_str);
	strcpy(ft_dest, dest_str);

	ft_strncat(ft_dest, src, size);
	strncat(dest, src, size);
	
	printf("%d\n", sgn(strcmp(ft_dest, dest)));
}

int	main(void)
{
	test("Hello", " world!", 13);
	test("Hello", " world!", 20);
	test("Hello", " w", 13);
	test("", "Hello world!", 15);
	
	return (0);
}
