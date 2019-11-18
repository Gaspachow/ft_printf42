/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:51:58 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/18 16:24:04 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putall(char *str, unsigned long long **arg)
{
	char	type;
	t_id	flags;

	flags = ft_flag_parsing(str + 1);
	if (flags.width == -2)
		flags.width = (int)(*arg++);
	if (flags.precision == -2)
		flags.precision = (int)(*arg++);
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
		ft_puthex(flags, (unsigned int)*arg, type);
	if (type == 'p')
		ft_putaddress(flags, (unsigned long long)*arg);
	return (ft_var_len(str));
}
