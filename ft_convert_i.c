/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:37:51 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/24 15:17:54 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_i(va_list ap, t_data *data)
{
	int i;

	i = 0;
	data->arg = ft_itoa(va_arg(ap, int));
	printf("data->arg : %s\n", data->arg);
	i = ft_atoi(data->arg);
	printf("%i\n", data->minus);
	printf("%i\n", data->zero);
	printf("%i\n", data->precision);
	printf("%i\n", data->width);
	printf("there are flags bitch !\n");
	data->len = data->width - ft_intlen(i);
	printf("data->len : %i\n", data->len);
	if (!data->dot)
	{
		if (data->len < 0 || data->minus)
			ft_putnbr(i, data);
	}
	else
	{
		ft_treat_precision(ft_intlen(i), data);
		ft_putnbr(i, data);
	}
}		

