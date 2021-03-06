/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:22:49 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/06 14:57:54 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_treat_precision(size_t len, t_data *data)
{
	int ilen;

	if (data->width > data->precision && !data->minus)
	{
		data->len = data->width - data->precision;
		//printf("treat_prec = data->len : %i\n", data->len); 
		ft_treat_width(data);
	}
	ilen = data->precision - len;	
	if (data->sign == 1 && (data->dot || (data->zero && !data->dot)))
	{
		//printf("data->sign : %i\n", data->sign);
		ft_putchar('-', data);
		data->len--;
		//printf("data->len : %i\n", data->len);
	}
	while (ilen)
	{

		ft_putchar('0', data);
		ilen--;
		data->len--;
	}
	//printf("data->len : %i\n", data->len);

}

