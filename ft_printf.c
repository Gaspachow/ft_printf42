/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:49:18 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/08 17:29:28 by gsmets           ###   ########.fr       */
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
	printf("\n\n-- count is %i\n\n", total_vars); // -------------------------------- PRINTF
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

int		launch_read(char *str, unsigned long long **args)
{
	int	count;
	int	vars_needed;

	count = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*(str++));
		else
		{
			vars_needed = 1 + ft_asterisk_count(str);
			str += ft_putall(str, &args[count]);
			count += vars_needed;
		}
	}
	return (0);
}

int		ft_putall(char *str, unsigned long long **arg)
{
	char	type;

	type = find_type(str + 1);
	if (type == 's')
		ft_putstr((char *)*arg);
	if (type == 'i' || type == 'd')
		ft_putnbr((int)*arg);
	if (type == 'c')
		ft_putchar((char)*arg);
	if (type == 'u')
		ft_putunbr((unsigned int)*arg);
	if (type == '%')
		write(1, "%", 1);
	return (ft_var_len(str));
}

int		ft_var_len(char *str)
{
	int	count;

	count = 2;
	str++;
	while (!is_type(*str))
	{
		str++;
		count++;
	}
	return (count);
}

int		is_type(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

int		is_flag(char c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	else
		return (0);
}

int		get_vars_count(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*(str + 1) == '%')
				str += 2;
			else
			{
				count++;
				str += ft_var_len(str);
			}
		}
		str++;
	}
	return (count);
}

char	find_type(char *str)
{
	while (*str)
	{
		if (is_type(*str))
			return (*str);
		str++;
	}
	return (0);
}

int		ft_asterisk_count(char *str)
{
	int count;

	count = 0;
	while (!is_type(*str))
	{
		if (*str == '*')
			count++;
	}
	return (count);
}
