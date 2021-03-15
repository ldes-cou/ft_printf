/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:06:50 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 12:15:30 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_type(t_data *data)
{
	data->f[0] = (t_func)(&ft_convert_c);
	data->f[1] = (t_func)(&ft_convert_s);
	data->f[2] = (t_func)(&ft_convert_p);
	data->f[3] = (t_func)(&ft_convert_i);
	data->f[4] = (t_func)(&ft_convert_u);
	data->f[5] = (t_func)(&ft_convert_x_lo);
	data->f[6] = (t_func)(&ft_convert_x_up);
	data->f[7] = (t_func)(&ft_convert_percent);
}

int		ft_is_type(char c)
{
	return (c == 'c' || c == 'd' || c == 's' || c == 'i' || c == 'p'
			|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}
