#include "libftprintf.h"

int		ft_treat_str_prec(char *str, t_data *data)
{
	size_t strlen;
 
	if (data->precision < (int)ft_strlen(str))
		strlen = data->precision;
	else
		strlen = ft_strlen(str);
	return (strlen);
}

void	ft_putnstr(char *str, size_t n, t_data *data)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i], data);
		i++;
	}
}
