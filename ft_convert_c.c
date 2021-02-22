/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:35:40 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/22 13:43:45 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_convert_c(va_list ap, t_data *data)
{
	data->i_arg = va_arg(ap, int);
	buf[0] = data->i_arg;
	if (ft_check_flags(data))
	{
		printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("there are flags bitch !\n");
		if (!data->precision)
		{
			data->len = data->width - ft_strlen(buf);
			if (data->len < 0)
				ft_putstr(buf, data);
			else
				ft_treat_width(ap, data);
		}
	}
	else
		ft_putstr(buf, data);
}
