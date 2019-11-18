/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:52:49 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/15 15:22:34 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putaddress(t_id flags, unsigned long long address)
{
	int addrlen;

	addrlen = getaddrlen(address);
	if (flags.precision != -1)
	{
		flags.zero = 0;
	}
	if (flags.left == 1)
	{
		if (flags.precision == -1)
			flags.precision = addrlen;
		ft_putleftaddress(flags, address, addrlen);
	}
	else
		ft_putaddressn(flags, address, addrlen);
}

void	ft_putaddressn(t_id flags, unsigned long long address, int addrlen)
{
	int		spacelen;
	int		preclen;
	char	c;

	spacelen = 0;
	c = ' ';
	preclen = flags.precision - addrlen;
	if (preclen < 0)
		preclen = 0;
	if (flags.width != -1)
		spacelen = flags.width - addrlen - preclen - 2;
	if (flags.zero)
		write(1, "0x", 2);
	if (spacelen > 0)
	{
		if (flags.zero)
			c = '0';
		while (spacelen--)
			write(1, &c, 1);
	}
	if (!flags.zero)
		write(1, "0x", 2);
	while (preclen-- > 0)
		write(1, "0", 1);
	ft_putptrnbr(address, 0);
}

void	ft_putleftaddress(t_id flags, unsigned long long address, int addrlen)
{
	int	spacelen;
	int	preclen;
	int	i;

	spacelen = 0;
	if (flags.precision == -1)
		flags.precision = addrlen;
	preclen = flags.precision - addrlen;
	if (preclen < 0)
		preclen = 0;
	i = preclen;
	write(1, "0x", 2);
	while (i--)
		write(1, "0", 1);
	ft_putptrnbr(address, 0);
	if (flags.width != -1)
		spacelen = flags.width - addrlen - preclen - 2;
	while (spacelen-- > 0)
		write(1, " ", 1);
}

int		getaddrlen(unsigned long long n)
{
	int	i;

	i = 1;
	while (n /= 16)
		i++;
	return (i);
}