/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/12 10:40:09 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		//n = ft_treat_int_neg(n, data);
		//printf("len_nb = %i\n", len_nb);
		data->len = data->width - len_nb;
		//printf("data->len = %i\n", data->len);
		if (data->precision < len_nb || ((data->wi > data->dot) && !data->zero))
			ft_treat_int(n, len_nb, data);
		else
		{
			n = ft_treat_int_neg(n, data);
			/*len_nb = (int)(ft_intlen(n));
			data->len = data->width - len_nb;*/
			ft_treat_precision(len_nb, data);
			if (data->dot && data->precision == 0 && n == 0)
				ft_putchar(' ', data);
			else
				ft_putnbr(n, data);
			if (data->minus && data->width > len_nb && data->precision <= data->width)
			{
				n = ft_treat_int_neg(n, data);
				ft_treat_width(data);
			}
		}
	}
	else
		ft_putnbr(n, data);
}		

void	ft_treat_int(int n, int len_nb, t_data *data)
{
	if (data->len <= 0 || data->minus)
	{	
		if (data->dot && data->precision == 0 && n == 0)
		{
			ft_putstr("", data);
			data->len++;
		}
		else
			ft_putnbr(n, data);
		if (data->width > len_nb)
		{
			if (data->zero)
				n = ft_treat_int_neg(n, data);
			ft_treat_width(data);
		}
	}
	else
	{
		if (data->zero)
			n = ft_treat_int_neg(n, data);
		ft_treat_width(data);
		if (data->dot && data->precision == 0 && n == 0)
			ft_putchar(' ', data);
		else
			ft_putnbr(n, data);
	}
}

int	ft_treat_int_neg(int n, t_data *data)
{
	long nb;
	size_t len;

	nb = (long)n;
	len = ft_intlen(nb);
	//printf("n : %i\n", n);
	if (nb < 0)
	{
		//data->len -= 1;
		if (!((data->zero && data->width > (int)len) && ((data->precision < (int)len) && data->dot)))
			nb *= -1;
		if (data->type == 'i' || data->type == 'd')
			data->sign = 1;	
	}
		//printf("nb : %li\n", nb);
		//printf("data->sign : %i\n", data->sign);
return (nb);
}

