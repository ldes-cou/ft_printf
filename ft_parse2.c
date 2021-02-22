/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldescou@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:49:55 by Sophie            #+#    #+#             */
/*   Updated: 2021/02/22 17:34:49 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_type(t_data *data)
{
	
	data->fun_array[0] = (f)&ft_convert_c;
	data->fun_array[1] = (f)&ft_convert_s;
	//data->fun_array[2] = &ft_convert_p;
	data->fun_array[3] = (f)&ft_convert_i;
	data->fun_array[4] = (f)&ft_convert_u;
	data->fun_array[5] = (f)&ft_convert_x_lo;
	data->fun_array[6] = (f)&ft_convert_x_up;
	data->fun_array[7] = (f)&ft_convert_percent;
}

int	ft_parse_type(const char *str, t_data *data)
{

	data->type  = ft_strchr_type(TYPE, str[1]);

	printf("data->type : %u\n", data->type);
	return (1);
}
//appeler la fun_array comme une fonction avec 'type' comme index
//===> fun_array[type](argument); 
