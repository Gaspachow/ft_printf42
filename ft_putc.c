/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 18:55:38 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/13 19:03:59 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
