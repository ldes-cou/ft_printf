/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:24:06 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/13 09:09:51 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_u(va_list ap, t_data *d)
{
	char		*display;
	int		len_str;

	d->u_arg = (va_arg(ap, unsigned int));
	display = ft_utoa(d->u_arg);
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
			if (d->dot && d->precision == 0 && d->u_arg == 0)
				ft_putchar(' ', d);
			else
				ft_putstr(display, d);
			if (d->minus && d->width > len_str && d->precision <= d->width)
				ft_treat_width(d);
		}
	}
	free(display);
}
