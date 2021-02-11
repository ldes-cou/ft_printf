/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldes-cou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 09:59:17 by Sophie            #+#    #+#             */
/*   Updated: 2021/02/11 14:49:55 by ldes-cou         ###   ########.fr       */
/*   Updated: 2021/02/10 10:38:28 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list ap;
	const char *format;
	t_data data;
	int i;

	va_start(ap, format);
	ft_init_struct(&t_data);
	while (format[i])
	{
		if (format[i] == '%')
			ft_parse(format, ap);
		else
			ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (data.count);
}

