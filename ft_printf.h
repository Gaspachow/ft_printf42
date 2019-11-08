/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:09:20 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/08 17:27:41 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h> // ------------------- PRINTF

int		get_vars_count(char *str);
int		is_blank(char c);
int		launch_read(char *str, unsigned long long **args);
int		ft_printf(char *str, ...);
int		ft_putall(char *str, unsigned long long **args);
int		is_type(char c);
int		is_flag(char c);
int		ft_var_len(char *str);
char	find_type(char *str);
int		ft_asterisk_count(char *str);

#endif

