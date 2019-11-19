/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:24:12 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/19 14:32:34 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_var_len(char *str)
{
	int	count;

	count = 2;
	str++;
	while (!is_type(*str) && *str)
	{
		str++;
		count++;
	}
	return (count);
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
			count++;
			if (*str == '%')
				str++;
			else
			{
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
