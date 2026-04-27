#include<unistd.h>
#include<string.h>
int ft_print_string(char *s)
{
	if(!s)
		return write(1,"(null)",6);
	return write(1,s,strlen(s));
}
