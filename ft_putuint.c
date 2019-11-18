/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 12:00:09 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/18 16:05:08 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putuint(t_id flags, unsigned int num)
{
	int numlen;

	numlen = getunumlen(num);
	if (flags.precision != -1)
	{
		flags.zero = 0;
	}
	if (flags.left == 1)
	{
		if (flags.precision == -1)
			flags.precision = numlen;
		ft_putleftuint(flags, num, numlen);
	}
	else
		ft_putuintn(flags, num, numlen);
	return (ft_uint_return(flags, numlen));
}

int		ft_uint_return(t_id flags, int numlen)
{
	if (flags.width >= flags.precision && flags.width >= numlen)
		return (flags.width);
	else if (flags.precision >= flags.width && flags.precision >= numlen)
		return (flags.precision);
	else
		return (numlen);
}

void	ft_putuintn(t_id flags, unsigned int num, int numlen)
{
	int		spacelen;
	int		preclen;
	char	c;

	spacelen = 0;
	c = ' ';
	preclen = flags.precision - numlen;
	if (preclen < 0)
		preclen = 0;
	if (flags.width != -1)
		spacelen = flags.width - numlen - preclen;
	if (spacelen > 0)
	{
		if (flags.zero)
			c = '0';
		while (spacelen--)
			write(1, &c, 1);
	}
	while (preclen-- > 0)
		write(1, "0", 1);
	ft_putunbr(num);
}

void	ft_putleftuint(t_id flags, unsigned int num, int numlen)
{
	int	spacelen;
	int	preclen;
	int	i;

	spacelen = 0;
	if (flags.precision == -1)
		flags.precision = numlen;
	preclen = flags.precision - numlen;
	if (preclen < 0)
		preclen = 0;
	i = preclen;
	while (i--)
		write(1, "0", 1);
	ft_putunbr(num);
	if (flags.width != -1)
		spacelen = flags.width - numlen - preclen;
	while (spacelen-- > 0)
		write(1, " ", 1);
}

int		getunumlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
