#include "ft_printf.h"

int	main()
{
	char str1[] = "Hello my friend!";
	char str2[] = "Hello my ennemy!";
	ft_printf("str1 is |%s| and str2 is |%s|\n", str1, str2);
}