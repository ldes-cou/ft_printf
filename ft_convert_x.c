/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:13:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/10 11:31:14 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void	ft_convert_x_lo(va_list ap, t_data *data)
{
	char *display;
	int	len_str;

	data->u_arg = (va_arg(ap, unsigned int));
	display = ft_itoa_base(data->u_arg, 16);
	if (!ft_check_flags(data))
		ft_putstr(display, data);
	else
	{
		len_str = ft_strlen(display);
		data->len = data->width - len_str;
		if (data->precision < len_str || ((data->wi > data->dot) && !data->zero))
			ft_treat_unsigned_int(display, len_str, data);
		else
		{
			ft_treat_precision(len_str, data);
			if (data->dot && data->precision == 0 && data->u_arg == 0)
					ft_putchar(' ', data);
			else
				ft_putstr(display, data);
			if (data->minus && data->width > len_str)
				ft_treat_width(data);
		}
	}
	free(display);
}

void	ft_treat_unsigned_int(char *display, int len_str, t_data *data)
{
	if (data->len < 0 || data->minus)
	{	
		if (data->dot && data->precision == 0 && data->u_arg == 0)
		{
			ft_putstr("", data);
			data->len++;
		}
		else
			ft_putstr(display, data);	
		if (data->width > len_str)
			ft_treat_width(data);
	}
	else
	{
		if (!data->dot || (data->precision < data->len))
			ft_treat_width(data);
		if (data->dot && data->precision == 0 && data->u_arg == 0)
			ft_putchar(' ', data);
		else
			ft_putstr(display, data);
	}

}

void	ft_convert_x_up(va_list ap, t_data *data)
{
	char 	*display;
	int	len_str;

	data->u_arg = (va_arg(ap, unsigned int));
	display = ft_itoa_base(data->u_arg, 16);
	display = ft_strtoupper(display);
	if (!ft_check_flags(data))
		ft_putstr(display, data);
	else
	{
		len_str = ft_strlen(display);
		data->len = data->width - len_str;
		if (data->precision < len_str || ((data->wi > data->dot) && !data->zero))
			ft_treat_unsigned_int(display, len_str, data);
		else
		{
			ft_treat_precision(len_str, data);
			if (data->dot && data->precision == 0 && data->u_arg == 0)
					ft_putchar(' ', data);
			else
				ft_putstr(display, data);
			if (data->minus && data->width > len_str)
				ft_treat_width(data);
		}
	}
	free(display);
}

