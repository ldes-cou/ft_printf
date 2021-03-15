/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:18:05 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 12:19:03 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	t_data	data;

	ft_init_struct(&data);
	data.i = 0;
	data.count = 0;
	va_start(ap, format);
	ft_preparser(format, &ap, &data);
	va_end(ap);
	return (data.count);
}
