/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:25:34 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 12:34:01 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_p(va_list ap, t_data *data)
{
	unsigned long long	n;
	char				*ptr;
	size_t				len;

	n = va_arg(ap, unsigned long long);
	ptr = ft_itoa_base(n, 16);
	if (data->dot && data->precision == 0 && n == 0)
		ft_strdup("");
	else
		len = ft_strlen(ptr) + 2;
	if (!ft_check_flags(data))
		ft_print_ptr(ptr, data);
	else
	{
		data->len = data->width - len;
		if (data->minus && data->width)
			ft_print_ptr(ptr, data);
		if (data->width > (int)len)
			ft_treat_width(data);
		if (!data->minus || (data->minus && !data->width))
			ft_print_ptr(ptr, data);
	}
	free(ptr);
}

void	ft_print_ptr(char *ptr, t_data *data)
{
	ft_putstr("0x", data);
	ft_putstr(ptr, data);
}
