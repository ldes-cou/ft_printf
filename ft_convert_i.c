/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/12 11:58:43 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_i(va_list ap, t_data *d)
{
	int n;
	int	len;

	d->arg = ft_itoa(va_arg(ap, int));		
	n = ft_atoi(d->arg);
	if (ft_check_flags(d))
	{
		len = (int)ft_intlen(n);
		d->len = d->width - len;
		if (d->precision < len || ((d->wi > d->dot) && !d->zero))
			ft_treat_int(n, len, d);
		else
		{
			n = ft_treat_int_neg(n, len, d);
			ft_treat_precision(len, d);
			if (d->dot && d->precision == 0 && n == 0)
				ft_putchar(' ', d);
			else
				ft_putnbr(n, d);
			if (d->minus && d->width > len && d->precision <= d->width)
			{
				n = ft_treat_int_neg(n, len, d);
				ft_treat_width(d);
			}
		}
	}
	else
		ft_putstr(d->arg, d);
}		

void	ft_treat_int(int n, int len, t_data *d)
{
	if (d->len <= 0 || d->minus)
	{	
		if (d->dot && d->precision == 0 && n == 0)
		{
			ft_putstr("", d);
			d->len++;
		}
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
			ft_putchar(' ', d);
		else
			ft_putnbr(n, d);
	}
}

int	ft_treat_int_neg(int n, int len, t_data *d)
{
	long nb;

	nb = (long)n;
	if (nb < 0)
	{
		if (!((d->zero && d->width > len) && ((d->precision < len) && d->dot)))
			nb *= -1;
		if (d->type == 'i' || d->type == 'd')
			d->sign = 1;	
	}
return (nb);
}

