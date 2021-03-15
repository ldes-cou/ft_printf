/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 11:21:08 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 12:36:56 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

# define FLAGS "-0.*"
# define TYPE "cspdiuxX%"

typedef void		(*t_func)(void *, ...);
typedef struct		s_data
{
	unsigned int	u_arg;
	char			*arg;
	int				width;
	int				wi;
	int				precision;
	int				dot;
	int				minus;
	int				zero;
	int				len;
	size_t			i;
	int				sign;
	char			type;
	int				count;
	int				wild;
	t_func			f[9];
}					t_data;
int					ft_printf(const char *format, ...);
/*
**utils
*/
void				ft_putnbr(int nb, t_data *data);
void				ft_putnbr_u(int nb, t_data *data);
void				ft_putchar(char c, t_data *data);
void				ft_putstr(char *str, t_data *data);
void				ft_putnbr_base(int nbr, char *base, t_data *data);
void				ft_putnstr(char *str, size_t n, t_data *data);
char				*ft_strtoupper(char *str);
/*
**initialisation
*/
void				ft_init_struct(t_data *data);
void				ft_init_type(t_data *data);
void				ft_init_flags(const char *format, va_list ap, t_data *data);
void				ft_init_minus_zero(const char *format, t_data *data);
/*
**parser
*/
void				ft_preparser(const char *str, va_list *ap, t_data *data);
void				ft_parser(const char *str, va_list *ap, t_data *data);
int					ft_check_flags(t_data *data);
int					ft_is_type(char c);
void				ft_treat_digit_flag(const char *format, t_data *data);
void				ft_treat_wild(const char *format, va_list ap, t_data *data);
int					ft_parse_type(const char *str, t_data *data);
/*
**handler
*/
void				ft_treat_width(t_data *data);
int					ft_treat_int_neg(int n, int len, t_data *d);
void				ft_treat_precision(size_t len, t_data *data);
int					ft_treat_str_prec(char *str, t_data *data);
void				ft_treat_unsigned_int(char *str, int len_nb, t_data *data);
void				ft_handle_width(int n, int len, t_data *d);
void				ft_handle_flags(int n, int len, t_data *d);
void				ft_handle_precision(int len, t_data *d);
/*
**conversions
*/
void				ft_convert_s(va_list ap, t_data *data);
void				ft_convert_i(va_list ap, t_data *data);
void				ft_convert_c(va_list ap, t_data *data);
void				ft_convert_x_lo(va_list ap, t_data *data);
void				ft_convert_x_up(va_list ap, t_data *data);
void				ft_convert_u(va_list ap, t_data *data);
void				ft_convert_p(va_list ap, t_data *data);
void				ft_convert_percent(t_data *data);
void				ft_print_ptr(char *ptr, t_data *data);
#endif
