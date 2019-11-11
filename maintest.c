#include "ft_printf.h"

int	main()
{
	char str1[] = "Hello my friend!";
	char str2[] = "Hello my ennemy!";
	int one = 100000;
	char yo = '.';
	// printf("str1 is |%s|\nstr2 is |%s|\nunsigned int one is |%u|\nand finally char yo is: |%.c| is 100%50% correct yo.\n", str1, str2, one, yo);
	printf("REAL my string is: |%-*.*s| and s2 is: |%-*s|\n", 42, 5, str1, 30, str2);
	ft_printf("MINE my string is: |%-*.*s| and s2 is: |%-*s|\n", 42, 5,  str1, 30, str2);
}