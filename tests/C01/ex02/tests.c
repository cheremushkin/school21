#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int main(void)
{
	int	n;
	int	m;

	n = 2;
	m = 4;
	
	ft_swap(&n, &m);
    ft_putchar(n + '0');
    ft_putchar(m + '0');
	return (0);
}
