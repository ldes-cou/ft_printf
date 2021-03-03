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
	//printf("width flag 0: %i\n", data->width);
	while (format[data->i])
	{	if (format[data->i] == '.')
			data->dot = 1;
		if (ft_isdigit(format[data->i]))//ici ne traite pas la precision sil y a juste un point
			ft_treat_digit_flag(format, data);
		if (format[data->i] == '*')
			ft_treat_wildcard(format, ap, data);
		if (ft_is_type(format[data->i]))
		{
			data->type = format[data->i];
			break ;
		}
		data->i++;
		//printf("format init_flags: %s", format);
	}
}
int	ft_check_flags(t_data *data)
{
	if (data->minus || data->zero || data->dot || data->wi)
		return (1);
	return (0);
}

void	ft_treat_wildcard(const char *format, va_list ap, t_data *data)
{
	if (format[data->i - 1] == '.')
	{
		data->dot = 1;
		data->precision = va_arg(ap, int);
		if (data->precision < 0)
		{
			data->precision = ft_treat_int_neg(data->precision, data);
			data->dot = 0;
		}		
		//printf("precision : %i\n", data->precision);
		//printf("data->dot : %i\n", data->dot);
	}
	else
	{
		data->width = va_arg(ap, int);
		if (data->width < 0)
			data->width= ft_treat_int_neg(data->width, data);
		//printf("width : %i\n", data->width);
	}
}
	
void	ft_treat_digit_flag(const char *format, t_data *data)
{
	if (!data->dot)
	{
		data->wi = 1;
		data->width = ft_atoi(&format[data->i]);
		if (data->width < 0)
			data->width= ft_treat_int_neg(data->width, data);
		if (data->width > 9)
			data->i += (ft_intlen(data->width) -1);		
		//printf("width : %i\n", data->width);
	}
	else
	{
		//printf("format = %c\n", format[data->i]);
		if (format[data->i] == 0)
			data->i += 2;
		data->precision = ft_atoi(&format[data->i]);
		//printf("precision : %i\n", data->precision);
		if (data->precision < 0)
			data->dot = 0;
		else
			data->dot = 1;
		if (data->precision > 9)
			data->i += (ft_intlen(data->precision) - 1);		
		//printf("lenprecision : %i\n", ft_intlen(data->precision));
		//printf("data->dot : %i\n", data->dot);
	}
}
