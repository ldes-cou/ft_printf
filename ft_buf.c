#include "libftprintf.h"
void	ft_init_buf(t_data *data)
{
	int i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		buf[i] = '\0';
		i++;
	}
	data->len = 0;
}

void	ft_fill_buf(char c, t_data *data)
{
	buf[data->len] = c;
	data->len++;
	if (data->len == BUFFER_SIZE)
		ft_display_buf(data);
}

void	ft_display_buf(t_data *data)
{
	write(1, buf, data->len);
	ft_init_buf(data);
}

