/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:55:38 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/18 16:30:31 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putc(t_id flags, char c)
{
	char	space;
	int		ret;

	space = ' ';
	ret = flags.width > 0 ? flags.width : 1;
	if (flags.zero)
		space = '0';
	if (flags.left)
		write(1, &c, 1);
	if (flags.width > 0)
		while (--flags.width)
			write(1, &space, 1);
	if (!flags.left)
		write(1, &c, 1);
	return (ret);
}
