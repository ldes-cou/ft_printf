#include "ft_printf.h"

void	ft_convert_percent(char c, t_data *data)
{
	c = '%';
	ft_putchar(c, data);
}
