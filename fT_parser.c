/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fT_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:55:41 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/24 12:12:03 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void ft_tab(const char *str, va_list *ap, t_data *data)
{		
	
	ft_init_type(data);
	while (str[data->i])
	{
		if (str[data->i] == '%')
		{
			data->i++;
			ft_init_flags(str, *ap, data);
			//ft_parse_type(str, data);
			if (str[data->i] == 'c')
				data->fun_array[0](ap, data);
			if (str[data->i] == 's')
				data->fun_array[1](ap, data);
			if (str[data->i] == 'p')
				data->fun_array[2](ap, data);
			if (str[data->i] == 'i' || str[data->i] == 'd')
				data->fun_array[3](ap, data);
			if (str[data->i] == 'u')
				data->fun_array[4](ap, data);
			if (str[data->i] == 'x')	
				data->fun_array[5](ap, data);
			if (str[data->i] == 'X')
				data->fun_array[6](ap, data);
			if (str[data->i] == '%')
				data->fun_array[7](data);
		}
		else
		{
			ft_putchar(str[data->i], data); //comment traiter les flags sans les afficher ?? 
		}
		data->i++;
	}
}	
