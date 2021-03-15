/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:35:40 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 10:26:12 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_c(va_list ap, t_data *data)
{
	int c;

	c = va_arg(ap, int);
	if (ft_check_flags(data))
	{
		data->len = data->width - 1;
		if (data->width <= 1 || data->minus)
		{
			ft_putchar(c, data);
			data->minus = 1;
		}
		if (data->width)
			ft_treat_width(data);
		if (!data->minus)
			ft_putchar(c, data);
	}
	else
		ft_putchar(c, data);
}
