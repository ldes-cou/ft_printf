/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/24 14:20:02 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(va_list ap, t_data *data)
{
	char *arg;
	size_t len;
	int i;

	i = 0;
	arg = va_arg(ap, char *);
	if (ft_check_flags(data))
	{
		printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("there are flags bitch !\n");
		len = ft_treat_str_prec(arg, data);
		data->len = data->width - len; 
		if (data->minus && data->width)
			ft_putnstr(arg, len, data);
		ft_treat_width(data);
		if (!data->minus)
			ft_putnstr(arg, len, data);
	}
	else
		ft_putstr(arg, data);
}










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
