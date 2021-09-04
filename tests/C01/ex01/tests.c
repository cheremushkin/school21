#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
 
int main(void)
{
	int nbr;
	int *p1 = &nbr;
	int **p2 = &p1;
	int ***p3 = &p2;
	int ****p4 = &p3;
	int *****p5 = &p4;
	int ******p6 = &p5;
	int *******p7 = &p6;
	int ********p8 = &p7;
	int *********p9 = &p8;
	
	ft_ultimate_ft(p9);
    ft_putchar(nbr / 10 + '0');
    ft_putchar(nbr % 10 + '0');
	return (0);
}
