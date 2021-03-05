/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/05 18:02:51 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_i(va_list ap, t_data *data)
{
	int n;
	int	len_nb;

	n = 0;
	data->arg = ft_itoa(va_arg(ap, int));		
	n = ft_atoi(data->arg);
	if (ft_check_flags(data))
	{
		
		len_nb = (int)(ft_intlen(n));
		data->len = data->width - len_nb;
		if (data->sign)
			data->len -= 1;
		if (data->precision < len_nb || ((data->wi > data->dot) && !data->zero))
			ft_treat_int(n, len_nb, data);
		else
		{
			n = ft_treat_int_neg(n, data);
			len_nb = (int)(ft_intlen(n));
			data->len = data->width - len_nb;
			ft_treat_precision(len_nb, data);
			if (data->dot && data->precision == 0 && n == 0)
					ft_putchar(' ', data);
			else
				ft_putnbr(n, data);
			if (data->minus && data->width > len_nb)
				ft_treat_width(data);
		}
	}
	else
		ft_putnbr(n, data);
}		

void	ft_treat_int(int n, int len_nb, t_data *data)
{
	if (data->len < 0 || data->minus)
	{	
		if (data->dot && data->precision == 0 && n == 0)
		{
			ft_putstr("", data);
			data->len++;
		}
		else
			ft_putnbr(n, data);
		if (data->width > len_nb)
			ft_treat_width(data);
	}
	else
	{	
		if (!data->precision)
		{
			n = ft_treat_int_neg(n, data);
			len_nb = (int)(ft_intlen(n));
			data->len = data->width - len_nb;
		}
		ft_treat_width(data);
		if (data->dot && data->precision == 0 && n == 0)
			ft_putchar(' ', data);
		else
			ft_putnbr(n, data);
	}
}

int	ft_treat_int_neg(int nb, t_data *data)
{
	if (nb < 0 && (data->dot || (data->zero && data->width)))
	{
		if (data->zero || data->precision > ft_intlen(nb))
			nb *= -1;
		if (data->type == 'i')
		{
			data->sign = 1;
			data->len -= 1;
		}
		//printf("data->type :%c", data->precision);
		//printf("data->sign : %i\n", data->sign);
	}
return (nb);
}

