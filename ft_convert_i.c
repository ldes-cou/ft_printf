/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/03/14 18:48:00 by Sophie           ###   ########.fr       */
=======
/*   Updated: 2021/03/14 14:39:51 by ldes-cou         ###   ########.fr       */
>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_i(va_list ap, t_data *d)
{
	int n;
	int	len;
<<<<<<< HEAD

	d->arg = ft_itoa(va_arg(ap, int));		
	n = ft_atoi(d->arg);
	len = (int)ft_intlen(n);
	if (ft_check_flags(d))
		ft_handle_flags(n, len, d);
=======
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
>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
	else
		ft_putstr(display, d);
	free(display);
}		

<<<<<<< HEAD
void	ft_handle_flags(int n, int len, t_data *d)
=======
void	ft_handle_flags(char *display, int len, t_data *d)
>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
{
	d->len = d->width - len;
	if (d->precision < len || ((d->wi > d->dot) && !d->zero))
		ft_handle_width(n, len, d);
	else
	{
<<<<<<< HEAD
		n = ft_treat_int_neg(n, len, d);
		ft_treat_precision(len, d);
		if (d->dot && d->precision == 0 && n == 0)
			ft_putchar(' ', d);
		else
			ft_putnbr(n, d);
=======
		ft_treat_int_neg(display, len, d);
		ft_treat_precision(display, len, d);
		ft_putstr(display, d);
>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
		if (d->minus && d->width > len && d->precision <= d->width)
		{
			n = ft_treat_int_neg(n, len, d);
			ft_treat_width(d);
		}
	}
}

<<<<<<< HEAD
void	ft_handle_width(int n, int len, t_data *d)
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
=======
void	ft_handle_width(char *display, int len, t_data *d)
{
	if (d->len <= 0 || d->minus)
	{	
		ft_putstr(display, d);
>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
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
<<<<<<< HEAD
		if (d->dot && d->precision == 0 && n == 0)
			ft_putchar(' ', d);
		//essayer de transformer tout en char *str
		else
			ft_putnbr(n, d);
	}
}

int	ft_treat_int_neg(int n, int len, t_data *d)
{
	long nb;

	nb = (long)n;
=======
		ft_putstr(display, d);
	}
}

void	ft_treat_int_neg(char *display, int len, t_data *d)
{
	long nb;

	nb = ft_atoi(display);

>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
	if (nb < 0)
	{
		if (!((d->zero && d->width > len) && ((d->precision < len) && d->dot)))
			nb *= -1;
		if (d->type == 'i' || d->type == 'd')
			d->sign = 1;	
	}
<<<<<<< HEAD
return (nb);
=======
	display = ft_itoa(nb);
>>>>>>> b7a34d2968f1cdc7c7b6d5b7b5ca75500b0e6b96
}

