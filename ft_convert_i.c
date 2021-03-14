/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/14 10:10:01 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_i(va_list ap, t_data *d)
{
	int	len;
	int 	n;

	d->arg = ft_itoa(va_arg(ap, int));
	n = ft_atoi(d->arg);
	len = (int)ft_strlen(d->arg);
	if (d->dot && d->precision == 0 && (n == 0))
	{
		d->arg = ft_strdup("");
		d->len = d->width;
	}
	else
		d->len = d->width - len;
	if (ft_check_flags(d))
		ft_handle_flags(len, d);
	else
		ft_putstr(d->arg, d);
	free(d->arg);
}		

void	ft_handle_flags(int len, t_data *d)
{
	
	if (d->precision < len || ((d->wi > d->dot) && !d->zero))
		ft_handle_width(len, d);
	else
	{
		ft_treat_int_neg(len, d);
		ft_treat_precision(len, d);
		ft_putstr(d->arg, d);
		if (d->minus && d->width > len && d->precision <= d->width)
		{
			ft_treat_int_neg(len, d);
			ft_treat_width(d);
		}
	}
}

void	ft_handle_width(int len, t_data *d)
{
	if (d->len <= 0 || d->minus)
	{	
		ft_putstr(d->arg, d);
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
		ft_putstr(d->arg, d);
	}
}

void	ft_treat_int_neg(int len, t_data *d)
{
	long nb;

	nb = ft_atoi(d->arg);

	if (nb < 0)
	{
		if (!((d->zero && d->width > len) && ((d->precision < len) && d->dot)))
			nb *= -1;
		if (d->type == 'i' || d->type == 'd')
			d->sign = 1;	
	}
	d->arg = ft_itoa(nb);
}

