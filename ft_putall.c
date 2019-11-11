/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:51:58 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/11 19:17:18 by gsmets           ###   ########.fr       */
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
		ft_putnbr((int)*arg);
	if (type == 'c')
		ft_putchar((char)*arg);
	if (type == 'u')
		ft_putunbr((unsigned int)*arg);
	if (type == '%')
		write(1, "%", 1);
	return (ft_var_len(str));
}

void	ft_puts(t_id flags, char *str)
{
	if (flags.left)
		ft_putleftstr(str, flags.precision, flags.width);
	else
		ft_putstrn(str, flags.precision, flags.width, flags.zero);
}

void	ft_putstrn(char *str, int strlen, int totallen, int flagzero)
{
	char	c;
	int		blanklen;

	if (flagzero)
		c = '0';
	else
		c = ' ';
	if (strlen == -1)
		strlen = ft_strlen(str);
	if (totallen == -1)
		totallen = ft_strlen(str);
	blanklen = totallen - strlen;
	while (blanklen-- > 0)
		write(1, &c, 1);
	while (strlen-- && *str)
		write(1, str++, 1);
}

void	ft_putleftstr(char *str, int strlen, int totallen)
{
	int		i;

	i = 0;
	if (strlen == -1)
		strlen = ft_strlen(str);
	if (totallen == -1)
		totallen = ft_strlen(str);
	while (*str && strlen-- > 0)
	{
		i++;
		totallen--;
	}
	write(1, str, i);
	while (totallen-- > 0)
		write(1, " ", 1);
}