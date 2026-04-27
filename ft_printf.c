#include"ft_printf.h"
int ft_printf(char *s,...)
{
	va_list ar;
	int i;
	int re;

	re=0;
	i=0;
	va_start(ar,s);
	while(s[i])
	{
		if(s[i]=='%' /* && no_flags(s+i)*/)
		{
			if(s[i+1]=='d')
				re+=ft_print_number(va_arg(ar,int));
			else if(s[i+1]=='c')
				re+=ft_print_char(va_arg(ar,int));
			else if(s[i+1]=='s')
                                re+=ft_print_string(va_arg(ar,char*));
			else if(s[i+1]=='p')
				re+=ft_print_pointer(va_arg(ar,void *));
			else if(s[i+1]=='x')
                                re+=ft_print_xs(va_arg(ar,unsigned int));
			else if(s[i+1]=='X')
                                re+=ft_print_xc(va_arg(ar,unsigned int));
			else if(s[i+1]=='i')
                                re+=ft_print_number(va_arg(ar,int));
			else if(s[i+1]=='%')
                                re+=write(1,"%",1);
			i++;
		}
		else
			re+=write(1,&s[i],1);
		i++;
	}
	va_end(ar);
	return re;
}
#include <stdio.h>
#include <limits.h>
int main(void)
{
    int ret1, ret2;
    int a = 42;
    int *ptr = &a;

    printf("===== CHAR (c) =====\n");
    ret1 = printf("real   : |%c|\n", 'A');
    ret2 = ft_printf("yours  : |%c|\n", 'A');
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%c|\n", 0);
    ret2 = ft_printf("yours  : |%c|\n", 0);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);


    printf("===== STRING (s) =====\n");
    ret1 = printf("real   : |%s|\n", "hello");
    ret2 = ft_printf("yours  : |%s|\n", "hello");
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%s|\n", "");
    ret2 = ft_printf("yours  : |%s|\n", "");
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%s|\n", NULL);
    ret2 = ft_printf("yours  : |%s|\n", NULL);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);


    printf("===== INT (d / i) =====\n");
    ret1 = printf("real   : |%d|\n", 42);
    ret2 = ft_printf("yours  : |%d|\n", 42);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%d|\n", -42);
    ret2 = ft_printf("yours  : |%d|\n", -42);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%d|\n", 0);
    ret2 = ft_printf("yours  : |%d|\n", 0);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%i|\n", INT_MAX);
    ret2 = ft_printf("yours  : |%i|\n", INT_MAX);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%i|\n", INT_MIN);
    ret2 = ft_printf("yours  : |%i|\n", INT_MIN);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);


    printf("===== UNSIGNED (u) =====\n");
    ret1 = printf("real   : |%u|\n", 42);
    ret2 = ft_printf("yours  : |%u|\n", 42);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%u|\n", -1);
    ret2 = ft_printf("yours  : |%u|\n", -1);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);


    printf("===== HEX (x / X) =====\n");
    ret1 = printf("real   : |%x|\n", 255);
    ret2 = ft_printf("yours  : |%x|\n", 255);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%X|\n", 255);
    ret2 = ft_printf("yours  : |%X|\n", 255);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%x|\n", 0);
    ret2 = ft_printf("yours  : |%x|\n", 0);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);


    printf("===== POINTER (p) =====\n");
    ret1 = printf("real   : |%p|\n", ptr);
    ret2 = ft_printf("yours  : |%p|\n", ptr);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    ret1 = printf("real   : |%p|\n", NULL);
    ret2 = ft_printf("yours  : |%p|\n", NULL);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);


    printf("===== MIX TEST =====\n");
    ret1 = printf("real   : |%c %s %d %i %u %x %X %p|\n",
                  'A', "test", 42, -42, 42, 255, 255, ptr);
    ret2 = ft_printf("yours  : |%c %s %d %i %u %x %X %p|\n",
                     'A', "test", 42, -42, 42, 255, 255, ptr);
    printf("len real=%d | len yours=%d\n\n", ret1, ret2);

    return 0;
}
