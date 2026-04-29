#include "ft_printf.h"

int	ft_print(char c, va_list *ar)
{
	if (c == 'd' || c == 'i')
		return (ft_print_number(va_arg(*ar, int)));
	else if (c == 's')
		return (ft_print_string(va_arg(*ar, char *)));
	else if (c == 'p')
		return (ft_print_pointer(va_arg(*ar, void *)));
	else if (c == 'c')
		return (ft_print_char(va_arg(*ar, int)));
	else if (c == 'x')
		return (ft_print_xs(va_arg(*ar, int)));
	else if (c == 'X')
		return (ft_print_xc(va_arg(*ar, int)));
	else if (c == 'u')
		return (ft_print_u(va_arg(*ar, unsigned int)));
	return (write(1, "%", 1));
}

static int	is_option(char c)
{
	char	*s;
	int		i;

	s = "udixXcsp%";
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ar;
	int		i;
	int		re;

	if (!s)
		return (-1);
	re = 0;
	i = 0;
	va_start(ar, s);
	while (s[i])
	{
		if (s[i] == '%' && is_option(s[i + 1]))
		{
			re += ft_print(s[i + 1], &ar);
			i += 2;
		}
		else
			re += write(1, &s[i++], 1);
	}
	va_end(ar);
	return (re);
}
