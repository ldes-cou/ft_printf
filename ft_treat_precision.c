/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 14:37:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/03 16:26:21 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_treat_precision(size_t len, t_data *data)
{
	if (data->width > data->precision && !data->minus)
	{
		data->len = data->width - data->precision;
		//printf("treat_prec = data->len : %i\n", data->len); 
		ft_treat_width(data);
	}	
	data->precision -= len;
	if (data->sign == 1 && (data->dot || data->zero))
	{
		//printf("data->sign : %i\n", data->sign);
		ft_putchar('-', data);
		data->len--;
		//printf("data->len : %i\n", data->len);
	}
	while (data->precision)
	{

		ft_putchar('0', data);
		data->precision--;
		data->len--;
	}
	//printf("data->len : %i\n", data->len);

}

