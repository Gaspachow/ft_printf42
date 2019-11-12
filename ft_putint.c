/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 17:35:05 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/12 17:35:33 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putint(t_id flags, int num)
{
	int numlen;

	numlen = getnumlen(num);
	if (flags.precision != -1)
	{
		flags.zero = 0;
	}
	if (flags.left == 1)
		ft_putleftint(flags, num, numlen);
	else
		ft_putintn(flags, num, numlen);
}

void	ft_putintn(t_id flags, int num, int numlen)
{
	int		spacelen;
	int		preclen;
	char	c;

	spacelen = 0;
	c = ' ';
	if (flags.precision == -1)
		flags.precision = numlen;
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
	ft_putnbr(num);
}

void	ft_putleftint(t_id flags, int num, int numlen)
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
	ft_putnbr(num);
	if (flags.width != -1)
		spacelen = flags.width - numlen - preclen;
	if (spacelen > 0)
	{
		while (spacelen--)
			write(1, " ", 1);
	}
}

int		getnumlen(int n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}
