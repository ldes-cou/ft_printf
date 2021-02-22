/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:37:51 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/22 14:24:47 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_i(va_list ap, t_data *data)
{
	int i;

	i = 0;
	data->arg = ft_itoa(va_arg(ap, int));
	printf("data->arg : %s\n", data->arg);
	while (data->arg[i])
	{
		buf[i] = data->arg[i];
		i++;
	}
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
			printf("data->len : %i\n", data->len);
			if (data->len < 0)
			{
				i = ft_atoi(data->arg);
				ft_putnbr(i, data);
			}
			else
				ft_treat_width(ap, data);
		}
	}
	else
	{
		i = ft_atoi(buf);
		printf("i_atoi : %i\n", i);
		ft_putnbr(i, data);
	}
}
