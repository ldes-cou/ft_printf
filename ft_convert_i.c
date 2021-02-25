/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:37:51 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/25 15:53:39 by ldes-cou         ###   ########.fr       */
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
	printf("n = %i\n", n);
	printf("sign = %i\n", data->sign);
	len_nb = (int)(ft_intlen(n));
	printf("data->arg : %s\n", data->arg);
	printf("%i\n", data->minus);
	printf("%i\n", data->zero);
	printf("%i\n", data->precision);
	printf("%i\n", data->width);
	printf("there are flags bitch !\n");
	data->len = data->width - ft_intlen(n);
	printf("data->len : %i\n", data->len);
	//mettre une condition si intlen < width ou < precision
	if (data->precision < len_nb || ((data->wi > data->dot) && !data->zero))
	{
		if (data->len < 0 || data->minus)
			ft_putnbr(n, data);
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
	}
}		

int	ft_treat_int(int nb, t_data *data)
{
	if (nb < 0)
	{
		nb *= -1;
		data->sign = 1;
	}
	return (nb);
}

