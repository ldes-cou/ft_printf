#include "libftprintf.h"

void	ft_treat_precision(size_t len, t_data *data)
{
	int i;

	i = -1;
	if (data->wi)
	{
		data->len = data->width - data->precision;
		printf("data->len width precision: %i\n", data->len);
		ft_treat_width(data);
	}
	data->len = data->precision - len;
	while (++i < data->len)
		ft_putchar('0', data);
}
