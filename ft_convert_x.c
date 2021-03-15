/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:13:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 12:17:06 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_x_lo(va_list ap, t_data *d)
{
	char	*display;
	int		len_str;

	d->u_arg = va_arg(ap, unsigned int);
	if (d->dot && d->precision == 0 && d->u_arg == 0)
		display = ft_strdup("");
	else
		display = ft_itoa_base(d->u_arg, 16);
	if (!ft_check_flags(d))
		ft_putstr(display, d);
	else
	{
		len_str = ft_strlen(display);
		d->len = d->width - len_str;
		if (d->precision < len_str || ((d->wi > d->dot) && !d->zero))
			ft_treat_unsigned_int(display, len_str, d);
		else
		{
			ft_treat_precision(len_str, d);
			ft_putstr(display, d);
			if (d->minus && d->width > len_str && d->width >= d->precision)
				ft_treat_width(d);
		}
	}
	free(display);
}

void	ft_treat_unsigned_int(char *display, int len_str, t_data *d)
{
	if (d->len < 0 || d->minus)
	{
		ft_putstr(display, d);
		if (d->width >= len_str)
			ft_treat_width(d);
	}
	else
	{
		if (!d->dot || (d->precision <= d->width))
			ft_treat_width(d);
		ft_putstr(display, d);
	}
}

void	ft_convert_x_up(va_list ap, t_data *d)
{
	char	*display;
	int		len_str;

	d->u_arg = (va_arg(ap, unsigned int));
	if (d->dot && d->precision == 0 && d->u_arg == 0)
		display = ft_strdup("");
	else
		display = ft_strtoupper(ft_itoa_base(d->u_arg, 16));
	if (!ft_check_flags(d))
		ft_putstr(display, d);
	else
	{
		len_str = ft_strlen(display);
		d->len = d->width - len_str;
		if (d->precision < len_str || ((d->wi > d->dot) && !d->zero))
			ft_treat_unsigned_int(display, len_str, d);
		else
		{
			ft_treat_precision(len_str, d);
			ft_putstr(display, d);
			if (d->minus && d->width >= d->precision)
				ft_treat_width(d);
		}
	}
	free(display);
}
