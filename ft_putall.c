/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:51:58 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/13 11:36:06 by gsmets           ###   ########.fr       */
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
		ft_puts(flags, (char *)*arg);
	if (type == 'i' || type == 'd')
		ft_putint(flags, (int)*arg);
	if (type == 'c')
		ft_putc(flags, (char)*arg);
	if (type == 'u')
		ft_putunbr((unsigned int)*arg);
	if (type == '%')
		write(1, "%", 1);
	return (ft_var_len(str));
}

void	ft_putc(t_id flags, char c)
{
	if (flags.left)
		write(1, &c, 1);
	if (flags.width > 0)
		while (--flags.width)
			write(1, " ", 1);
	if (!flags.left)
		write(1, &c, 1);
}
