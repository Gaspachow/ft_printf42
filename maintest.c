#include "ft_printf.h"

int	main()
{
	char str1[] = "Hello my friend!";
	char str2[] = "Hello my ennemy!";
	int one = 100000;
	char yo = '.';
	printf("str1 is |%s|\nstr2 is |%s|\nunsigned int one is |%u|\nand finally char yo is: |%.c| is 100%% correct yo.\n", str1, str2, one, yo);
	// printf("my string is: |%45%s|", str1, str2);
}