/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:40:30 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/03 16:32:07 by ldes-cou         ###   ########.fr       */
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
		n = ft_treat_int_neg(n, data);
		//printf("n = %i\n", n);
		//printf("sign = %i\n", data->sign);
		len_nb = (int)(ft_intlen(n));
		/*printf("data->arg : %s\n", data->arg);
		printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("there are flags bitch !\n");*/
		data->len = data->width - len_nb;
		//printf("data->len : %i\n", data->len);
		//mettre une condition si intlen < width ou < precision
		if (data->precision < len_nb || ((data->wi > data->dot) && !data->zero))
		{
			if (data->len < 0 || data->minus)
			{
				ft_putnbr(n, data);
				ft_treat_width(data);
			}
			else
			{
				ft_treat_width(data);
				if (data->precision == 0 && n == 0)
					ft_putchar(' ', data);
				else
					ft_putnbr(n, data);
			}
		}
		else
		{
			ft_treat_precision(len_nb, data);
			if (data->precision == 0 && n == 0)
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

int	ft_treat_int_neg(int nb, t_data *data)
{
	if (nb < 0 && (data->dot || (data->zero && data->width)))
	{
		nb *= -1;
		if (data->type == 'i')
			data->sign = 1;
		//printf("data->type :%c", data->precision);
		//printf("data->sign : %i\n", data->sign);
	}
	return (nb);
}

