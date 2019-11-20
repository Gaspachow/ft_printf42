/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:03:48 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/20 11:32:40 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		launch_read(char *str, va_list *args)
{
	int		rvalue;

	rvalue = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str != '%')
		{
			ft_putchar(*(str++));
			rvalue++;
		}
		else
		{
			rvalue += ft_putall(str, args);
			str += ft_var_len(str);
		}
	}
	return (rvalue);
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
	while (!is_type(*str) && *str)
	{
		if (*str == '*')
			count++;
		str++;
	}
	if (*str == '%')
		count--;
	return (count);
}
