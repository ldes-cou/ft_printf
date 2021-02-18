#include "libftprintf.h"

void	ft_init_flags(const char *format, va_list ap, t_data *data)
{
	while (!ft_is_type(format[data->i]))
	{
		if (format[data->i] == '-')
			data->minus = 1;
		if (format[data->i] == '0')
			data->zero = 1;
		if(ft_isdigit(format[data->i]))
		{
			if (format[data->i - 1] == '.')
			{
				data->precision = ft_atoi(&format[data->i]);
				printf("precision : %i\n", data->precision);
			}
			else
			{
				data->width = ft_atoi(&format[data->i]);//convertir atoi
				printf("width : %i\n", data->width);
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
		data->i++; //ici pb avec la fonction, s'il y a des choses à afficher il les skip ...
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
	
	
