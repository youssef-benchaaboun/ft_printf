#include <unistd.h>
#include <stdio.h>
static int print_hex(unsigned long long nb)
{
	char *base="0123456789abcdef";
	int re;
	re=0;
	if(nb>=16)
		re+=print_hex(nb/16);
	re+=write(1,&base[nb%16],1);
	return re;
}
int ft_print_pointer(void *p)
{
	int re;

	re=0;
	if(!p)
		return write(1,"(nil)",5);
	unsigned long long value;

	re+=write(1,"0x",2);
	value=(unsigned long long)p;
	re+=print_hex(value);
	return re;
}
