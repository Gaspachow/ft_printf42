/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:17:49 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/11 19:18:02 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_id	ft_flag_parsing(char *str)
{
	int		len;
	t_id	flags;

	len = -1;
	flags = ft_init_flags();
	while (*str == '0' || *str == '-')
	{
		if (*str == '-')
		{
			flags.left = 1;
			flags.zero = 0;
		}
		else if (*str == '0')
			if (flags.left == 0)
				flags.zero = 1;
		str++;
	}
	return (ft_flag_width(str, &flags));
}

t_id	ft_flag_width(char *str, t_id *flags)
{
	if (!is_type(*str))
	{
		if (*str == '*')
			flags->width = -2;
		else
			flags->width = ft_atoi(str);
	}
	while (ft_isdigit(*str) || *str == '*')
		str++;
	if (*str == '.')
	{
		str++;
		if (*str == '*')
			flags->precision = -2;
		else
			flags->precision = ft_atoi(str);
		while (ft_isdigit(*str) || *str == '*')
			str++;
	}
	return (*flags);
}

t_id	ft_init_flags(void)
{
	t_id flags;

	flags.precision = -1;
	flags.width = -1;
	flags.left = 0;
	flags.zero = 0;
	return (flags);
}