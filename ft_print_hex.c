#include "ft_printf.h"

static int	print_hex(unsigned int nb, char *base)
{
	int	re;

	re = 0;
	if (nb >= 16)
		re += print_hex(nb / 16, base);
	re += write(1, &base[nb % 16], 1);
	return (re);
}

int ft_print_xs(unsigned nb) 
{
	return (print_hex(nb, "0123456789abcdef"));
}

int ft_print_xc(unsigned nb) 
{
	return (print_hex(nb, "0123456789ABCDEF"));
}
