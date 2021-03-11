/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:24:06 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/11 21:10:57 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_u(va_list ap, t_data *data)
{
	char *display;
	int	len_str;

	data->u_arg = (va_arg(ap, unsigned int));
	display = ft_utoa(data->u_arg);
	if (!ft_check_flags(data))
		ft_putstr(display, data);
	else
	{
		len_str = ft_strlen(display);
		data->len = data->width - len_str;
		if (data->precision < len_str || ((data->wi > data->dot) && !data->zero))
			ft_treat_unsigned_int(display, len_str, data);
		else
		{
			ft_treat_precision(len_str, data);
			if (data->dot && data->precision == 0 && data->u_arg == 0)
					ft_putchar(' ', data);
			else
				ft_putstr(display, data);
			if (data->minus && data->width > len_str && data->precision <= data->width)
				ft_treat_width(data);
		}
	}
	free(display);
}
