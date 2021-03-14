/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/14 14:39:51 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_i(va_list ap, t_data *d)
{
	int	len;
	int 	n;
	char display[32];

	display = ft_itoa(va_arg(ap, int));
	n = ft_atoi(display);
	len = (int)ft_strlen(display);
	if (d->dot && d->precision == 0 && (n == 0))
	{
		display = ft_strcp("");
		d->len = d->width;
	}
	else
		d->len = d->width - len;
	if (ft_check_flags(d))
		ft_handle_flags(display, len, d);
	else
		ft_putstr(display, d);
	free(display);
}		

void	ft_handle_flags(char *display, int len, t_data *d)
{
	
	if (d->precision < len || ((d->wi > d->dot) && !d->zero))
		ft_handle_width(len, d);
	else
	{
		ft_treat_int_neg(display, len, d);
		ft_treat_precision(display, len, d);
		ft_putstr(display, d);
		if (d->minus && d->width > len && d->precision <= d->width)
		{
			ft_treat_int_neg(len, d);
			ft_treat_width(d);
		}
	}
}

void	ft_handle_width(char *display, int len, t_data *d)
{
	if (d->len <= 0 || d->minus)
	{	
		ft_putstr(display, d);
		if (d->width > len)
		{
			if (d->zero)
				ft_treat_int_neg(len, d);
			ft_treat_width(d);
		}
	}
	else
	{
		if (d->zero)
			ft_treat_int_neg(len, d);
		ft_treat_width(d);
		ft_putstr(display, d);
	}
}

void	ft_treat_int_neg(char *display, int len, t_data *d)
{
	long nb;

	nb = ft_atoi(display);

	if (nb < 0)
	{
		if (!((d->zero && d->width > len) && ((d->precision < len) && d->dot)))
			nb *= -1;
		if (d->type == 'i' || d->type == 'd')
			d->sign = 1;	
	}
	display = ft_itoa(nb);
}

