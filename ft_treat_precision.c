#include "libftprintf.h"

void	ft_treat_precision(size_t len, t_data *data)
{
	if (data->width > data->precision)
	{
		data->len = data->width - data->precision;
		printf("treat_prec = data->len : %i\n", data->len); 
		ft_treat_width(data);
		data->len = data->precision - len;
	}
	else
		data->len = data->precision - len;
	if (data->sign == 1)
		ft_putchar('-', data);
	while (data->len)
	{

		ft_putchar('0', data);
		data->len--;
	}
}
