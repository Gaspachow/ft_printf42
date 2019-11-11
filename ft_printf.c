/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:49:18 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/11 19:20:10 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	int					total_vars;
	int					count;
	unsigned long long	**args;
	va_list				ap;

	total_vars = get_vars_count(str);
	printf("-- count is %i\n", total_vars); // -------------------------------- PRINTF
	count = 0;
	args = malloc((total_vars + 1) * sizeof(unsigned long long *));
	va_start(ap, str);
	while (count < total_vars)
	{
		args[count] = va_arg(ap, unsigned long long *);
		count++;
	}
	args[count] = NULL;
	va_end(ap);
	launch_read(str, args);
	free(args);
	return (1);
}

