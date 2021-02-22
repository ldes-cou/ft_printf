/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/22 14:02:30 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(va_list ap, t_data *data)
{
	int i;
	
	i = 0;
	data->arg = va_arg(ap, char *);
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
				ft_putstr(buf, data);
			else
				ft_treat_width(ap, data);
		}
	}
	else
		ft_putstr(buf, data);
}
