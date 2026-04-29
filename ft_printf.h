#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_print_u(unsigned int n);
int	ft_strlen(char *s);
int	ft_printf(const char *s, ...);
int	ft_print_char(char c);
int	ft_print_xs(unsigned int nb);
int	ft_print_xc(unsigned int nb);
int	ft_print_number(int nb);
int	ft_print_pointer(void *p);
int	ft_print_string(char *s);
#endif
