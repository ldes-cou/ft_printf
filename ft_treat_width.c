/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:40:19 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/14 22:16:01 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_width(t_data *data)
{
	int i;

	i = -1;

	if ((data->zero && !data->dot) && !data->minus)
	{
		if (data->sign == 1)
		{
			ft_putchar('-', data);
			//data->len--;
			//printf("treat_wi :data->len : %i\n", data->len);
		}
		if ((data->type == 'i' || data->type == 'd') && data->zero && data->precision)
		{
			while (++i < data->len)
	
				ft_putchar(' ', data);
		}	
		else
		{
			while (++i < data->len)
				ft_putchar('0', data);
		}

	}
	else
	{
		//if (data->sign && (data->type == 'i' || data->type == 'd') && !data->minus)
		//	data->len--;
		while (data->len)
		{
			ft_putchar(' ', data);
			data->len--;
		}
	}	return ;
}
	
