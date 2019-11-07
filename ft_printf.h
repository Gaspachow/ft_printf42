/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:09:20 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/07 19:54:12 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include "libft/libft.h"

int	get_vars_count(char *str);
int	is_blank(char c);
int	launch_read(char *str, unsigned long long **args);
int	ft_printf(char *str, ...);
int	ft_putall(char *str, unsigned long long *args);
int	is_blank(char c);
int	ft_var_len(char *str);

#endif

