/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:03:48 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/07 19:18:48 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	is_blank(char c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v' ||
		c == ' ')
		return (1);
	else
		return (0);
}

int	get_var_type(char *str, char **ptr, int count)
{

}