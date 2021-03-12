/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/12 10:37:29 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_s(va_list ap, t_data *data)
{
	char *arg;
	size_t len;
	int i;

	i = 0;
	arg = va_arg(ap, char *);
	if (arg == NULL || arg == 0)
		arg = "(null)";
	if (ft_check_flags(data))
	{
		/*printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("%i\n", data->dot);
		printf("there are flags bitch !\n");*/
		len = ft_treat_str_prec(arg, data);
		data->len = data->width - len;
		if (data->minus && data->width)
		{
			ft_putnstr(arg, len, data);
			//printf("1");
		}
		if (data->width > (int)len)
		{
			ft_treat_width(data);
			//printf("2");
		}
		if(!data->minus || (data->minus && !data->width))
		{
			ft_putnstr(arg, len, data);
			//printf("3");
		}
	}
	else
	{
		ft_putstr(arg, data);
			//printf("4");
		//printf("here");
	}
}

//void	ft_treat_null(









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
