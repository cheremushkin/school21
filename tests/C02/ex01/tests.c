#include <stdio.h>

int main(void)
{
	char	src1[] = "This is a very long string";
	char	src2[] = "Short";
	char	dest1[7];
	char	dest1_[8];
	char	dest2[10];
	char	*output1;
	char	output1_[8];
	char	*output2;
	
	output1 = ft_strncpy(dest1, src1, 7);
	for (int i = 0; i < 7; i++)
	{
		dest1_[i] = dest1[i];
		output1_[i] = output1[i];
	}
	dest1_[7] = '\0';
	output1_[7] = '\0';
	printf("%s, %s, %s\n", src1, dest1_, output1_);	
	output2 = ft_strncpy(dest2, src2, 10);
	printf("%s, %s, %s, %zu", src2, dest2, output2, sizeof(dest2));
	return (0);
}
