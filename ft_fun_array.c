/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldescou@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:49:55 by Sophie            #+#    #+#             */
/*   Updated: 2021/03/02 14:24:26 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_type(t_data *data)
{
	
	data->fun_array[0] = (f)&ft_convert_c;
	data->fun_array[1] = (f)&ft_convert_s;
	//data->fun_array[2] = &ft_convert_p;
	data->fun_array[3] = (f)&ft_convert_i;
	/*data->fun_array[4] = (f)&ft_convert_u;
	data->fun_array[5] = (f)&ft_convert_x_lo;
	data->fun_array[6] = (f)&ft_convert_x_up;
	data->fun_array[7] = (f)&ft_convert_percent;*/
}

int	ft_is_type(char c)
{
	return (c == 'c' || c == 'd' || c == 's' || c == 'i' || c == 'p' || c == 'u' || c == 'x' || c == 'X' || c == '%');
}
//appeler la fun_array comme une fonction avec 'type' comme index
//===> fun_array[type](argument); 
