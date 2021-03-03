/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:40:19 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/03 21:59:17 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_treat_width(t_data *data)
{
	int i;

	i = -1;

	if ((data->zero && !data->minus))
	{
		if (data->sign == 1)
		{
			//printf("treat_wi :data->sign : %i\n", data->sign);
			ft_putchar('-', data);
			//data->len--;
			//printf("treat_wi :data->len : %i\n", data->len);
		}
		while (++i < data->len)
			ft_putchar('0', data);
	}
	else
	{
		while (data->len)
		{
			ft_putchar(' ', data);
			data->len--;
		}
	}	return ;
}
	
