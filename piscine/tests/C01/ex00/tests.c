#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int main(void)
{
	int nbr;
	
	ft_ft(&nbr);
    ft_putchar(nbr / 10 + '0');
    ft_putchar(nbr % 10 + '0');
	return (0);
}
