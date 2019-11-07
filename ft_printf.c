/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:49:18 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/07 20:51:45 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *str, ...)
{
	int					total_vars;
	int					count;
	unsigned long long	**args;
	va_list				ap;

	total_vars = get_vars_count(str);
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

int	launch_read(char *str, unsigned long long **args)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*(str++));
		else if (args[count])
		{
			str += ft_putall(str, args[count]);
			count++;
		}
		else
			return (0);
	}
	return (0);
}

int	ft_putall(char *str, unsigned long long *args)
{
	char	*ptr;

	ptr = (char *)args;
	if (*(str + 1) == 's')
		ft_putstr(ptr);
	return (2);
}

int	ft_var_len(char *str)
{
	int	count;

	count = 0;
	while (!is_blank(*str))
	{
		str++;
		count++;
	}
	return (count);
}

int	is_blank(char c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||
		c == ' ')
		return (1);
	else
		return (0);
}

int	get_vars_count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			count++;
			while (!(is_blank(*str)) && *str)
				str++;
		}
		str++;
	}
	return (count);
}