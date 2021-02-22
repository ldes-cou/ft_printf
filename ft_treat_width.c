#include "libftprintf.h"

void	ft_treat_width(va_list ap, t_data *data)
{
	int i;

	i = -1;
	if (data->minus)
	{
		//if (data->type == 0 || data->type == 1)
		ft_putstr(buf, data);
		//if (data->type == 3 || data->type == 4)
		{
			data->i_arg = ft_atoi(data->arg);
			ft_putnbr(data->i_arg, data);
		}
		while (data->len)
		{	
			ft_putchar(' ', data);
			data->len--;
		}
	}
	else if (data->zero && (!data->minus))
	{
		while (++i < data->len)
			ft_putchar('0', data); //comportement indéfini de printf avec 0 et s ou c;
		ft_putstr(buf, data);
	}
	else
	{	while (++i < data->len)
			ft_putchar(' ', data);//str[i] = ' ';//allouer de la mémoire ou trouver un moyen de le stocker dans le 
		ft_putstr(buf, data);//ft_strcat(str, str);
	}
	return ;
}
	

	
