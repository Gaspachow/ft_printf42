/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 19:25:30 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/18 17:03:46 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_puts(t_id flags, char *str)
{
	int strlen;

	strlen = ft_strlen(str);
	if (flags.precision < 0 || flags.precision > strlen)
		flags.precision = strlen;
	if (flags.width < 0)
		flags.width = flags.precision;
	if (flags.left)
		ft_putleftstr(str, flags.precision, flags.width);
	else
		ft_putstrn(str, flags.precision, flags.width, flags.zero);
	return (ft_s_return(flags, strlen));
}

int		ft_s_return(t_id flags, int strlen)
{
	if (flags.width >= flags.precision)
		return (flags.width);
	if (flags.precision >= flags.width)
		return (flags.precision);
	return (strlen);
}

void	ft_putstrn(char *str, int strlen, int totallen, int flagzero)
{
	char	c;
	int		blanklen;

	if (flagzero)
		c = '0';
	else
		c = ' ';
	blanklen = totallen - strlen;
	while (blanklen-- > 0)
		write(1, &c, 1);
	while (*str && strlen--)
		write(1, str++, 1);
}

void	ft_putleftstr(char *str, int strlen, int totallen)
{
	int		i;
	int		blanklen;

	i = 0;
	blanklen = totallen - strlen;
	while (str[i] && strlen-- > 0)
		i++;
	write(1, str, i);
	while (blanklen-- > 0)
		write(1, " ", 1);
}
