/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 11:11:53 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/11 21:02:55 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_tab(const char *str, va_list *ap, t_data *data)
{		
	
	ft_init_type(data);
	size_t len;

	len = ft_strlen(str);
	while (str[data->i]  != '\0' && data->i < len)
	{
		if (str[data->i] == '%')
		{
			data->i++;
			ft_init_struct(data);
			ft_init_flags(str, *ap, data);
			if (str[data->i] == 'c')
				data->fun_array[0](ap, data);
			else if (str[data->i] == 's')
				data->fun_array[1](ap, data);
			else if (str[data->i] == 'p')
				data->fun_array[2](ap, data);
			else if (str[data->i] == 'i' || str[data->i] == 'd')
				data->fun_array[3](ap, data);
			else if (str[data->i] == 'u')
				data->fun_array[4](ap, data);
			else if (str[data->i] == 'x')	
				data->fun_array[5](ap, data);
			else if (str[data->i] == 'X')
				data->fun_array[6](ap, data);
			else if (str[data->i] == '%')
				data->fun_array[7](data);
		}
		else if (str[data->i] && data->i < len)
		{
			ft_putchar(str[data->i], data);
		}
		data->i++;
		if (data->i >= len)
			break ;
	}
}

void	ft_init_struct(t_data *data)
{
	//ft_bzero(data, sizeof(data));
	data->width = 0;
	data->precision = 0;
	data->len = 0;
	data->minus = 0;
	data->zero = 0;
	data->dot = 0;
	data->wi = 0;
	data->sign = 0;
}
