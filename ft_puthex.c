/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:52:49 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/15 13:59:54 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(t_id flags, unsigned int num, char type)
{
	int numlen;
	int allcaps;

	allcaps = 0;
	numlen = gethexlen(num);
	if (type == 'X')
		allcaps = 1;
	if (flags.precision != -1)
	{
		flags.zero = 0;
	}
	if (flags.left == 1)
	{
		if (flags.precision == -1)
			flags.precision = numlen;
		ft_putlefthex(flags, num, numlen, allcaps);
	}
	else
		ft_puthexn(flags, num, numlen, allcaps);
}

void	ft_puthexn(t_id flags, unsigned int num, int numlen, int allcaps)
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
	ft_puthexnbr(num, allcaps);
}

void	ft_putlefthex(t_id flags, unsigned int num, int numlen, int allcaps)
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
	ft_puthexnbr(num, allcaps);
	if (flags.width != -1)
		spacelen = flags.width - numlen - preclen;
	while (spacelen-- > 0)
		write(1, " ", 1);
}

int		gethexlen(unsigned int n)
{
	int	i;

	i = 1;
	while (n /= 16)
		i++;
	return (i);
}
