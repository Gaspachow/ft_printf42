#include "ft_printf.h"

int	main()
{
	char str1[] = "Hello my friend!";
	char str2[] = "Hello my ennemy!";
	// int one = -2183647;
	// char yo = 'C';
	// ft_printf("str1 is |%s|\nstr2 is |%s|\nunsigned int one is |%u|\nand finally char yo is: |%.c| is 100%% correct yo.\n", str1, str2, one, yo);
	// printf("REAL my string is: |%-*.*s| and s2 is: |%-*s|\n", 42, 5, str1, 30, str2);
	// ft_printf("MINE my string is: |%-*.*s| and s2 is: |%-*s|\n", 42, 5,  str1, 30, str2);
	// ft_printf("FT int i = |%-*.*i|\n", 20, 6, one);
	// printf("RL int i = |%-*.*i|\n", 20, 6, one);
	int i =    printf("real one - testing char |%1x|\n", 2548);
	int j = ft_printf("me       - testing char |%1x|\n", 2548);

	printf("   printf return value: %i\nft_printf return value: %i\n", i, j);
}