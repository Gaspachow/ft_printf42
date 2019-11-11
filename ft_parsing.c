/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:03:48 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/11 19:20:33 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		launch_read(char *str, unsigned long long **args)
{
	int		count;
	char	*tmp;

	count = 0;
	while (*str)
	{
		if (*str != '%')
			ft_putchar(*(str++));
		else
		{
			tmp = str;
			str += ft_putall(str, &args[count]);
			count += 1 + ft_asterisk_count(tmp + 1);
		}
	}
	return (0);
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
			str++;
			if (*str == '%')
				str += 2;
			else
			{
				count++;
				while (!(is_type(*str)) && *str)
				{
					if (*str == '*')
						count++;
					str++;
				}
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
	while (!is_type(*str) && *str)
	{
		if (*str == '*')
			count++;
		str++;
	}
	return (count);
}

