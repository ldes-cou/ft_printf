#include "libftprintf.h"

void	ft_treat_width(t_data *data)
{
	int i;

	i = -1;
	if (data->minus)
	{
		while (data->len)
		{	
			ft_putchar(' ', data);
			data->len--;
		}
	}
	if (data->zero && !data->minus)
	{
		while (++i < data->len)
			ft_putchar('0', data);
	}
	else
	{
		while (++i < data->len)
			ft_putchar(' ', data);
	}	return ;
}
	
