#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
void    ft_putnbr(int nb)
{
	unsigned int    n;

	if (nb < 0)
	{
		ft_putchar('-');
		n = -1 * nb;
	}
	else
		n = nb;
 	if (n > 9)
 	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
 	}
	else
		ft_putchar(n + '0');
}

void	ft_print_int_array(int *ar, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_putnbr(*(ar + i));

		if (i != size - 1)
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		i++;
	}
}
 
int	main(void)
{
	int	ar4[4] = {1, 0, 8, 6};
	int	ar5[5] = {2, -1, 1, -6, 2};
	
	ft_sort_int_tab(ar4, 4);
	ft_print_int_array(ar4, 4);
	ft_putchar('\n');
	ft_sort_int_tab(ar5, 5);
	ft_print_int_array(ar5, 5);
	return (0);
}
