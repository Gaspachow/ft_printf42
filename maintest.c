#include "ft_printf.h"

int	main()
{
	char str1[] = "Hello my friend!";
	char str2[] = "Hello my ennemy!";
	int one = -25555;
	ft_printf("str1 is |%s|\nstr2 is |%s|\nint one is |%d|\n", str1, str2, one);
}