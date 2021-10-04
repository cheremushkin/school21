#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int main(void)
{
	int	a;
	int	b;
	int	div;
	int	mod;
	
	a = 18;
	b = 4;

	ft_div_mod(a, b, &div, &mod);
    ft_putchar(div + '0');
    ft_putchar(mod + '0');
	return (0);
}
