#include <stdio.h>

int main(void)
{
	char	src1[] = "String";
	char	dest1[5];
	unsigned int	src1_len;
	char	src2[] = "String";
	char	dest2[7];
	unsigned int	src2_len;
	char	src3[] = "String";
	char	dest3[10];
	unsigned int	src3_len;
	char	src4[] = "String";
	char	dest4[0];
	unsigned int	src4_len;

	src1_len = ft_strlcpy(dest1, src1, 5);
	src2_len = ft_strlcpy(dest2, src2, 7);
	src3_len = ft_strlcpy(dest3, src3, 10);
	src4_len = ft_strlcpy(dest4, src4, 0);
	
	printf("%s, %s, %d\n", src1, dest1, src1_len);
	printf("%s, %s, %d\n", src2, dest2, src2_len);
	printf("%s, %s, %d\n", src3, dest3, src3_len);
	printf("%s, %d", src4, src4_len);
	
	return (0);
}
