/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 14:36:29 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/18 10:42:38 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_convert_s(va_list ap, t_data *data)
{

	if (ft_check_flags(data))
	{
		printf("%i\n", data->minus);
		printf("%i\n", data->zero);
		printf("%i\n", data->precision);
		printf("%i\n", data->width);
		printf("there are flags bitch !\n");
		//ft_putstr(va_arg(ap, char *), data);
	}
	ft_putstr(va_arg(ap, char *), data);
}
