#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int main(void)
{
	int	a;
	int	b;
	
	a = 18;
	b = 4;

	ft_ultimate_div_mod(&a, &b);
    ft_putchar(a + '0');
    ft_putchar(b + '0');
	return (0);
}
