/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/19 18:23:42 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(va_list ap, t_data *data)
{
	char *str;
	int i;
	
	 = 0;
	str = va_arg(ap, char *);
	while (str[i])
	{
		data->buf[i] = str[i]
		i++;
	}
	if (ft_check_flags(data))
	{
		printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("there are flags bitch !\n");
		if (data->width && !data->precision)
		{
			data->len = data->width - ft_strlen(data->buf);
			if (data->len < 0)
				ft_putstr(str, data);
			else
				ft_treat_width(ap, data);
		}
	}
	else
		ft_putstr(data->buf, data);
}
