/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 12:12:54 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/12 12:14:45 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_percent(t_data *data)
{
	char c;

	c = '%';
	data->precision = 0;
	if (ft_check_flags(data))
	{
		data->len = data->width - 1;
		if ((data->width <= 1 || data->minus))
		{
			ft_putchar(c, data);
			data->minus = 1;
		}
		ft_treat_width(data);
		if (!data->minus)
			ft_putchar(c, data);
	}
	else
		ft_putchar(c, data);
}
