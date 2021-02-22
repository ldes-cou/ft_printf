#include "libftprintf.h"

void	ft_init_flags(const char *format, va_list ap, t_data *data)
{	
	if (format[data->i] == '0')
	{
		data->zero = 1;
		data->i++;
	}
	if (format[data->i] == '-')
	{
		data->minus = 1;
		data->i++;
	}

	printf("width flag 0: %i\n", data->width);
	while (!ft_is_type(format[data->i]))
	{
		if (ft_isdigit(format[data->i]))
		{
			if (format[data->i - 1] == '.')
			{
				data->precision = ft_atoi(&format[data->i]);
				if (data->precision > 9)
					data->i += (ft_intlen(data->precision) - 1);		
				printf("precision : %i\n", data->precision);
			}
			else
			{
				data->width = ft_atoi(&format[data->i]);//convertir atoi
				printf("width 1 : %i\n", data->width);
				if (data->width > 9)
					data->i += (ft_intlen(data->width) -1);		
				printf("width 2: %i\n", data->width);
			}
		}
		if (format[data->i] == '*')
		{
			if (format[data->i - 1] == '.')
			{
				data->precision = va_arg(ap, int);
				printf("precision : %i\n", data->precision);
			}
			else
			{
				data->width = va_arg(ap, int);//faire la conversion atoi dans la fonction
				printf("width : %i\n", data->width);
			}
		}
		data->i++;
		//printf("format init_flags: %s", format);
	}
}
int	ft_check_flags(t_data *data)
{
	return (data->minus || data->zero || data->precision || data->width);

}
int	ft_is_type(char c)
{
	return (c == 'c' || c == 'd' || c == 's' || c == 'i' || c == 'p' || c == 'u' || c == 'x' || c == 'X' || c == '%');//sinon faire un define TYPE et chercher dedans avec un ft_strchr(sans retourner la localisation)
}
size_t		ft_intlen(int n)
{
	size_t		len;

	len = 0;
	if (!n)
		len++;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}
