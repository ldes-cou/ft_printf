#include "libftprintf.h"

void	ft_convert_percent(t_data *data)
{
	char c;
	
	c = '%';
	if (ft_check_flags(data))
	{
		data->len = data->width - 1;
		if ((data->width <= 1 || data->minus))
		{
			ft_putchar(c, data);
			data->minus = 1;
		}
		ft_treat_width(data);
		if (!data->minus)
			ft_putchar(c, data);
	}
	else
		ft_putchar(c, data);
}
