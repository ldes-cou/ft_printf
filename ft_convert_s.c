/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/12 11:31:10 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(va_list ap, t_data *data)
{
	char *arg;
	size_t len;
	int i;

	i = 0;
	arg = va_arg(ap, char *);
	if (arg == NULL || arg == 0)
		arg = "(null)";
	if (ft_check_flags(data))
	{
		len = ft_treat_str_prec(arg, data);
		data->len = data->width - len;
		if (data->minus && data->width)
			ft_putnstr(arg, len, data);
		if (data->width > (int)len)
			ft_treat_width(data);
		if(!data->minus || (data->minus && !data->width))
			ft_putnstr(arg, len, data);
	}
	else
		ft_putstr(arg, data);
}

