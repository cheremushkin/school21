void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int main(void)
{
	ft_putstr("String");
	ft_putchar('\n');
	ft_putstr("String with number 42");
	ft_putchar('\n');
	ft_putstr("Ooo spooky!");
	return (0);
}
