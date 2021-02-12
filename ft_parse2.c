/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldescou@student.42.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 08:49:55 by Sophie            #+#    #+#             */
/*   Updated: 2021/02/12 10:54:04 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_type(t_data *data)
{
	
	data->fun_array[0] = (f)&ft_convert_c;
	data->fun_array[1] = (f)&ft_convert_s;
	//data->fun_array[2] = &ft_convert_p;
	data->fun_array[3] = (f)&ft_convert_i;
	//data->fun_array[4] = &ft_convert_u;
	//data->fun_array[5] = &ft_convert_x_lo;
	//data->fun_array[6] = &ft_convert_x_up;
	//data->fun_array[7] = &ft_convert_%;
}

/*int	ft_parse_type(char *str, t_data *data)
{
	int type_index;

	type_index  = ft_strchr(TYPE, str[0]);
	data->type = type_index - TYPE;
	return (1);
}
*/
//appeler la fun_array comme une fonction avec 'type' comme index
//===> fun_array[type](argument); 
