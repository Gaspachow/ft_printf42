/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:51:58 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/19 16:30:44 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putall(char *str, va_list *arg)
{
	char	type;
	t_id	flags;

	flags = ft_flag_parsing(str + 1);
	if (flags.width == -2 || flags.precision == -2)
		ft_flags_wildcard(&flags, arg);
	type = find_type(str + 1);
	if (type == 's')
		return (ft_puts(flags, va_arg(*arg, char *)));
	if (type == 'i' || type == 'd')
		return (ft_putint(flags, va_arg(*arg, int)));
	if (type == 'c')
		return (ft_putc(flags, va_arg(*arg, int)));
	if (type == 'u')
		return (ft_putuint(flags, va_arg(*arg, unsigned int)));
	if (type == '%')
		return (ft_putc(flags, '%'));
	if (type == 'x' || type == 'X')
		return (ft_puthex(flags, va_arg(*arg, unsigned int), type));
	if (type == 'p')
		return (ft_putaddress(flags, va_arg(*arg, unsigned long long int)));
	return (0);
}

int		ft_flags_wildcard(t_id *flags, va_list *arg)
{
	int argvalue;

	argvalue = 0;
	if (flags->width == -2)
	{
		argvalue = va_arg(*arg, int);
		if (argvalue < 0)
		{
			flags->width = -argvalue;
			flags->left = 1;
		}
		else
			flags->width = argvalue;
	}
	if (flags->precision == -2)
	{
		if ((int)(*arg < 0))
			flags->precision = -1;
		else
			flags->precision = va_arg(*arg, int);
	}
	return (1);
}

int		ft_null_precision(int width)
{
	int i;

	i = 0;
	if (width > 0)
	{
		while (i++ < width)
			write(1, " ", 1);
		return (width);
	}
	return (0);
}

int		ft_nullptr_precision(int left, int width)
{
	int i;

	i = 2;
	if (width > 2)
	{
		if (left)
			write(1, "0x", 2);
		while (i++ < width)
			write(1, " ", 1);
		if (!left)
			write(1, "0x", 2);
		return (width);
	}
	write(1, "0x", 2);
	return (2);
}
