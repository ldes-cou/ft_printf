/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/14 22:04:09 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_i(va_list ap, t_data *d)
{
	long long n;
	int	len;

	n = va_arg(ap, int);		
	d->arg = ft_itoa(n);
	
	if (d->dot && d->precision == 0 && n == 0)
		len = 0;
	else
		len = (int)ft_intlen(n);
	if (ft_check_flags(d))
		ft_handle_flags(n, len, d);
	else
		ft_putstr(d->arg, d);
	free(d->arg);
}		

void	ft_handle_flags(int n, int len, t_data *d)
{
	d->len = d->width - len;
	if (d->precision < len || ((d->wi > d->dot) && !d->zero))
		ft_handle_width(n, len, d);
	else
	{
		n = ft_treat_int_neg(n, len, d);
		ft_treat_precision(len, d);
		if (d->dot && d->precision == 0 && n == 0)
			ft_putstr("", d);
		else
			ft_putnbr(n, d);
		if (d->minus && d->width > len && d->precision <= d->width)
		{
			n = ft_treat_int_neg(n, len, d);
			ft_treat_width(d);
		}
	}
}

void	ft_handle_width(int n, int len, t_data *d)
{
	if (d->len <= 0 || d->minus)
	{	
		if (d->dot && d->precision == 0 && n == 0)
			ft_putstr("", d);
		else
			ft_putnbr(n, d);
		if (d->width > len)
		{
			if (d->zero)
				n = ft_treat_int_neg(n, len, d);
			ft_treat_width(d);
		}
	}
	else
	{
		if (d->zero)
			n = ft_treat_int_neg(n, len, d);
		ft_treat_width(d);
		if (d->dot && d->precision == 0 && n == 0)
			ft_putstr("", d);
		else
			ft_putnbr(n, d);
	}
}

int	ft_treat_int_neg(int n, int len, t_data *d)
{

	if (n < 0)
	{
		if (!((d->zero && d->width > len) && ((d->precision < len) && d->dot)))
			n *= -1;
		if (d->type == 'i' || d->type == 'd')
			d->sign = 1;	
	}
	return (n);
}

