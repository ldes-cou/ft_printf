/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/23 21:16:30 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(char *arg, t_data *data)
{
	char *arg;

	arg = va_arg(ap, char *);
	data->len = ft_strlen(arg);
	if (!ft_check_flags)
		ft_putstr(arg, data);	
	if (data->precision)
		if (data->precision < data->len)
			ft_treat_str_prec(arg, data);
		if 
			








	/*if (ft_check_flags(data))
	{
		printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("there are flags bitch !\n");
		if (!data->precision && )
		{
			data->len = data->width - ft_strlen(arg);
			printf("data->len : %i\n", data->len); 
			if (data->len < 0)
				ft_putstr(arg, data);
			else
				ft_treat_width(data);
		}
	}
	else
		ft_putstr(arg, data);
}*/
