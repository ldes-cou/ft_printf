#include "libftprintf.h"

void	ft_treat_width(va_list ap, t_data *data)
{
	int i;
	
	i = -1;
	if (data->zero && !data->minus)
	{
		while (++i < data->len)
			ft_putchar('0', data);//data->buf[i] = '0';
		ft_putstr(data->buf, data);//ft_strcat(data->buf, str);
	}
	if (data->minus)
	{
		ft_putstr(str, data);//data->buf = ft_strcpy(str);
		while (data->len)
		{	
			ft_putchar(' ', data);//data->buf[ft_strdata->len(str)] = ' ';
			data->len--;
		}
	}
	else
	{	while (++i < data->len)
			ft_putchar(' ', data);//data->buf[i] = ' ';//allouer de la mémoire ou trouver un moyen de le stocker dans le 
		ft_putstr(data->buf, data);//ft_strcat(data->buf, str);
	}
	return ;
}
	

	
