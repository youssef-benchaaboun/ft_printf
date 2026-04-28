#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include<unistd.h>
#include<unistd.h>
#include<stdarg.h>
#include<stdio.h>
int ft_strlen(char *s);
int     ft_printf(const char *s, ...);
int ft_print_char(char c);
int ft_print_xs(unsigned nb);
int ft_print_xc(unsigned nb);
int ft_print_number(int nb);
int ft_print_pointer(void *p);
int ft_print_string(char *s);
#endif
