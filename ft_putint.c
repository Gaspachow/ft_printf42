/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:35:05 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/19 14:11:13 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putint(t_id flags, int num)
{
	int			numlen;
	int			is_negative;
	long int	n;

	if (flags.precision == 0 && !num)
		return (ft_null_precision(flags.width));
	n = num;
	is_negative = 0;
	numlen = getnumlen(n);
	if (n < 0)
	{
		is_negative = 1;
		n = -n;
	}
	if (flags.precision != -1)
		flags.zero = 0;
	if (flags.left == 1)
	{
		ft_putleftint(flags, n, numlen, is_negative);
	}
	else
		ft_putintn(flags, n, numlen, is_negative);
	return (ft_int_return(flags, numlen, is_negative));
}

int		ft_int_return(t_id flags, int numlen, int is_neg)
{
	if (is_neg)
	{
		if (flags.width <= flags.precision && flags.width >= numlen)
			return (flags.precision + 1);
		if (flags.width == -1 && flags.precision > numlen)
			return (flags.precision + 1);
		if (flags.width >= flags.precision && flags.width >= numlen)
			return (flags.width);
		else if (flags.precision >= flags.width && flags.precision >= numlen)
			return (flags.precision + 1);
		return (numlen);
	}
	if (flags.width >= flags.precision && flags.width >= numlen)
		return (flags.width);
	else if (flags.precision >= flags.width && flags.precision >= numlen)
		return (flags.precision);
	else
		return (numlen);
}

void	ft_putintn(t_id flags, long int num, int numlen, int is_neg)
{
	int		spacelen;
	int		preclen;
	char	c;

	spacelen = 0;
	preclen = 0;
	c = ' ';
	if (flags.precision > 0)
		preclen = flags.precision - numlen + is_neg;
	if (preclen < 0)
		preclen = 0;
	if (flags.width != -1)
		spacelen = flags.width - numlen - preclen;
	if (flags.zero)
		c = '0';
	if (is_neg && flags.zero)
		write(1, "-", 1);
	while (spacelen-- > 0)
		write(1, &c, 1);
	if (is_neg && !flags.zero)
		write(1, "-", 1);
	while (preclen-- > 0)
		write(1, "0", 1);
	ft_putunbr(num);
}

void	ft_putleftint(t_id flags, long int num, int numlen, int is_neg)
{
	int	spacelen;
	int	preclen;
	int	i;

	spacelen = 0;
	preclen = 0;
	if (flags.precision > 0)
		preclen = flags.precision - numlen + is_neg;
	if (preclen < 0)
		preclen = 0;
	i = preclen;
	if (is_neg)
		write(1, "-", 1);
	while (i--)
		write(1, "0", 1);
	ft_putunbr(num);
	if (flags.width != -1)
		spacelen = flags.width - numlen - preclen;
	while (spacelen-- > 0)
		write(1, " ", 1);
}

int		getnumlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
		i++;
	while (n /= 10)
		i++;
	return (i);
}
