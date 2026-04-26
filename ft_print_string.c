#include"ft_printf.h"
int ft_print_string(char *s)
{
	return write(1,s,ft_strlen(s));
}
