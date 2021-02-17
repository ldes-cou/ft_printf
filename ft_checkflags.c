#include "libftprintf.h"

void	ft_init_flags(const char *format, va_list ap, t_data *data)
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
				data->precision = va_arg(ap, int);
			else
				data->width = va_arg(ap, int);
				printf("width : %i\n", data->width);
		}
		data->i++; //ici pb avec la fonction, s'il y a des choses à afficher il les skip ...
		//printf("format init_flags: %s", format);
	}
}
int	ft_check_flags(t_data *data)
{
	if (data->minus || data->zero || data->precision || data->width)
		return(1);
	return (0);
}
