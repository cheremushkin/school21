#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int	main(void)
{
	int	n;
	
	n = ft_strlen("String");
	ft_putchar(n + '0');
	ft_putchar('\n');
	n = ft_strlen("String with number 42");
	ft_putchar(n / 10 + '0');
	ft_putchar(n % 10 + '0');
	ft_putchar('\n');
	n = ft_strlen("Ooo spooky!");
	ft_putchar(n / 10 + '0');
	ft_putchar(n % 10 + '0');
	return (0);
}
