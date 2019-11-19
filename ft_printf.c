/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 13:49:18 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/19 16:16:03 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(char *str, ...)
{
	int					total_vars;
	va_list				ap;
	int					ret;

	total_vars = get_vars_count(str);
	va_start(ap, str);
	ret = launch_read(str, &ap);
	va_end(ap);
	return (ret);
}
