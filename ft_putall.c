/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:51:58 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/19 13:27:39 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putall(char *str, unsigned long long *arg)
{
	char	type;
	t_id	flags;

	flags = ft_flag_parsing(str + 1);
	if (flags.width == -2 || flags.precision == -2)
		arg += ft_flags_wildcard(&flags, arg);
	type = find_type(str + 1);
	if (type == 's')
		return (ft_puts(flags, (char *)*arg));
	if (type == 'i' || type == 'd')
		return (ft_putint(flags, (int)*arg));
	if (type == 'c')
		return (ft_putc(flags, (char)*arg));
	if (type == 'u')
		return (ft_putuint(flags, (unsigned int)*arg));
	if (type == '%')
		return (ft_putc(flags, '%'));
	if (type == 'x' || type == 'X')
		return (ft_puthex(flags, (unsigned int)*arg, type));
	if (type == 'p')
		return (ft_putaddress(flags, (unsigned long long)*arg));
	return (ft_var_len(str));
}

int		ft_flags_wildcard(t_id *flags, unsigned long long *arg)
{
	int count;

	count = 0;
	if (flags->width == -2)
	{
		if ((int)(*arg) < 0)
		{
			flags->width = -(int)(*arg++);
			flags->left = 1;
		}
		else
			flags->width = (int)(*arg++);
		count++;
	}
	if (flags->precision == -2)
	{
		if ((int)(*arg < 0))
			flags->precision = -1;
		else
			flags->precision = (int)(*arg);
		count++;
	}
	return (count);
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
