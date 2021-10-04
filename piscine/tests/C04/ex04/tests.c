void	test(int n, char *base)
{
	ft_putnbr_base(n, base);
	ft_putchar('\n');
}

int main(void)
{
	test(0, "01");
	test(0, "poneyvif");
	test(-255, "0123456789ABCDEF");
	test(11, "baaaka");
	test(2, "a");
	test(3, "ab");
	test(10, "0123456789+");
	test(10, "0123456789a");
	test(-2147483648, "0123456789ABCDEFG");
	test(-2147483648, "0123456789ABCDEFG\e");
	test(-2147483648, "yx");
	return (0);
}