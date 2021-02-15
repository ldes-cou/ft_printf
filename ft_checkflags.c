#include "libftprintf.h"

void	ft_init_flags(const char *format, t_data *data)
{
	while (format[data->i])
	{
		if (format[data->i] == '-')
			data->minus = 1;
		if (format[data->i] == '0')
			data->zero = 1;
		if(ft_isdigit(format[data->i]))
		{
			if (format[data->i - 1])
				data->precision = format[data->i];
			else
				data->width = format[data->i];
		}
		if (format[data->i] == '*')
		{
			if (format[data->i - 1])
				data->wildcard_precision = 1;
			else
				data->wildcard_width = 1;
		}
		data->i++;
	}
}
int	ft_check_flags(t_data *data)
{
	ft_init_flags(format, data);
	if (data->minus || data->zero || data->precision || data->width)
		return(1);
	return (0);
}
