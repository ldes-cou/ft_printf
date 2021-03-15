/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 11:23:11 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 12:37:33 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_flags(const char *format, va_list ap, t_data *data)
{
	ft_init_minus_zero(format, data);
	while (format[data->i])
	{
		if (format[data->i] == '.')
			data->dot = 1;
		if (ft_isdigit(format[data->i]))
			ft_treat_digit_flag(format, data);
		if (format[data->i] == '*')
			ft_treat_wild(format, ap, data);
		if (ft_is_type(format[data->i]))
		{
			data->type = format[data->i];
			break ;
		}
		data->i++;
	}
}

int		ft_check_flags(t_data *data)
{
	if (data->dot || data->wi)
		return (1);
	return (0);
}

void	ft_treat_wild(const char *format, va_list ap, t_data *data)
{
	data->wild = 1;
	if (format[data->i - 1] == '.')
	{
		data->dot = 1;
		data->precision = va_arg(ap, int);
		if (data->precision < 0)
		{
			data->dot = 0;
			data->precision = 0;
		}
	}
	else
	{
		data->wi = 1;
		data->width = va_arg(ap, int);
		if (data->width < 0)
		{
			data->width *= -1;
			data->minus = 1;
		}
	}
}

void	ft_treat_digit_flag(const char *format, t_data *data)
{
	if (!data->dot)
	{
		data->wi = 1;
		data->width = ft_atoi(&format[data->i]);
		if (data->width > 9)
			data->i += (ft_intlen(data->width) - 1);
	}
	else
	{
		if (format[data->i] == 0)
			data->i += 2;
		data->precision = ft_atoi(&format[data->i]);
		if (data->precision < 0)
			data->dot = 0;
		else
			data->dot = 1;
		if (data->precision > 9)
			data->i += (ft_intlen(data->precision) - 1);
	}
}

void	ft_init_minus_zero(const char *format, t_data *data)
{
	if (format[data->i] == '0')
	{
		data->zero = 1;
		while (format[data->i] == '0')
			data->i++;
	}
	if (format[data->i] == '-')
	{
		data->minus = 1;
		while (format[data->i] == '-')
			data->i++;
	}
}
