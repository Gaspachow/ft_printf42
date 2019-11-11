/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:09:20 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/11 18:11:54 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdio.h> // ------------------- PRINTF

typedef	struct	s_id
{
	int			precision;
	int			width;
	int			left;
	int			zero;
}				t_id;

int				get_vars_count(char *str);
int				is_blank(char c);
int				launch_read(char *str, unsigned long long **args);
int				ft_printf(char *str, ...);
int				ft_putall(char *str, unsigned long long **args);
int				is_type(char c);
int				is_flag(char c);
int				ft_var_len(char *str);
char			find_type(char *str);
int				ft_asterisk_count(char *str);
t_id			ft_flag_parsing(char *str);
t_id			ft_flag_width(char *str, t_id *flags);
t_id			ft_init_flags(void);
void			ft_puts(t_id flags, char *str);
void			ft_putstrn(char *str, int strlen, int totallen, int flagzero);
void			ft_putleftstr(char *str, int strlen, int totallen);

#endif
