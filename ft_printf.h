/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsmets <gsmets@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 12:09:20 by gsmets            #+#    #+#             */
/*   Updated: 2019/11/18 16:58:23 by gsmets           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

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
int				ft_puts(t_id flags, char *str);
void			ft_putstrn(char *str, int strlen, int totallen, int flagzero);
void			ft_putleftstr(char *str, int strlen, int totallen);
int				ft_putint(t_id flags, int num);
void			ft_putleftint(t_id flags, long int num, int numlen, int is_neg);
int				getnumlen(int n);
void			ft_putintn(t_id flags, long int num, int numlen, int is_neg);
int				ft_putc(t_id flags, char c);
void			ft_printminus(int flag_zero, int *num);
int				ft_putuint(t_id flags, unsigned int num);
void			ft_putuintn(t_id flags, unsigned int num, int numlen);
void			ft_putleftuint(t_id flags, unsigned int num, int numlen);
int				getunumlen(unsigned int n);
int				ft_puthex(t_id flags, unsigned int num, char type);
void			ft_puthexn(t_id flags, unsigned int num, int len, int caps);
void			ft_putlefthex(t_id flags, unsigned int num, int len, int caps);
int				gethexlen(unsigned int n);
int				ft_putaddress(t_id flags, unsigned long long ad);
void			ft_putaddressn(t_id flags, unsigned long long ad, int adlen);
void			ft_putleftaddress(t_id flags, unsigned long long ad, int adlen);
int				getaddrlen(unsigned long long n);
int				ft_int_return(t_id flags, int numlen, int is_neg);
int				ft_s_return(t_id flags, char *str, int strlen);
int				ft_uint_return(t_id flags, int numlen);
int				ft_hex_return(t_id flags, int numlen);
int				ft_ptr_return(t_id flags, int adlen);

#endif
