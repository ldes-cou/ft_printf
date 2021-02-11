/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:55:41 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/11 22:35:34 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_tab(const char *str, va_list *ap, t_data *data)
{
	ft_init_type(data);
	while (str[data->i])
	{
		if (str[data->i] == '%')
		{
			if (str[data->i + 1] == 'c')
				data->fun_array[0](ap);
			if (str[data->i + 1] == 's')
				data->fun_array[1](ap);
			if (str[data->i] == 'p')
				data->fun_array[2](ap);
			if (str[data->i] == 'i' || str[data->i] == 'd')
				data->fun_array[3](ap);
			if (str[data->i] == 'u')
				data->fun_array[4](ap);
			if (str[data->i] == 'x')	
				data->fun_array[5](ap);
			if (str[data->i] == 'x')
				data->fun_array[6](ap);
			if (str[data->i] == 'x')
				data->fun_array[7](ap);
			if (str[data->i] == 'X')
				data->fun_array[8](ap);
			data->i += 2;
		}
		else
		{
			ft_putchar(str[data->i], data);
			data->i++;
		}
			
	}
}	
