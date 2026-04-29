#include "ft_printf.h"

int	ft_print_number(int nb)
{
	long	n;
	char	c;
	int		re;

	n = nb;
	re = 0;
	if (n < 0)
	{
		n = -1 * n;
		re += write(1, "-", 1);
	}
	if (n > 9)
		re += ft_print_number(n / 10);
	c = n % 10 + '0';
	re += write(1, &c, 1);
	return (re);
}

int	ft_print_u(unsigned int n)
{
	int		re;
	char	c;

	re = 0;
	if (n > 9)
		re += ft_print_number(n / 10);
	c = n % 10 + '0';
	re += write(1, &c, 1);
	return (re);
}
