/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 11:50:07 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/12 10:38:53 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_convert_c(const char *str)
{
	va_list ap;
	int 	res;
	int		i;

	i = 0;
	va_start(ap, str);
	while (str[data.i])
	{
		if (str[data.i] == '%')
		{
			res = va_arg(ap, int);
			if (str[i + 1] == 'c')
			{
				ft_putchar(res);
			}
		}
	i++;
	}
	va_end(ap);
	return (1);
}
void	ft_convert_i(const char *str, ...)
{
	va_list ap;
	int 	res;
	int		i;
	
	i = 0;
	va_start(ap, str);
	while (str[data.i])
	{
		if (str[i] == '%')
		{
			res = va_arg(ap, int);
			if (str[i + 1] == 'd' || str[i +1] == 'i')
			{
				ft_putnbr(res);
			}
		}
	i++;
	}
	va_end(ap);
	return (1);
}
int ft_convert_s(const char *str, ...)
{
	va_list ap;
	char 	*res;
	t_data data;

	va_start(ap, str);
	while (str[data.i])
	{
		if (str[data.i] == '%')
		{
			res = va_arg(ap, char *);
			if (str[data.i + 1] == 's')
				count = ft_putstr(res, count);
		}
	i++;
	}
	va_end(ap);
	return (count);
}

