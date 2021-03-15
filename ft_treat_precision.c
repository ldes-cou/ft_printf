/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:22:49 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 10:48:06 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_precision(size_t len, t_data *data)
{
	int ilen;
	int i;

	i = 0;
	if (data->sign == 1)
		ilen = 1;
	else
		ilen = 0;
	data->width = data->precision == data->width ? 0 : data->width;
	if (data->width > data->precision && !data->minus)
	{
		data->len = data->width - data->precision;
		if (data->sign == 1)
			data->len--;
		ft_treat_width(data);
	}
	ilen += (data->precision - len);
	if (data->sign == 1 && (data->dot || (data->zero && !data->dot)))
		ft_putchar('-', data);
	while (ilen)
	{
		ft_putchar('0', data);
		ilen--;
		data->len--;
	}
}
