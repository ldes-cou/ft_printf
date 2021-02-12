/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:58:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/12 12:03:11 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	printf("%i", data->count);
	data->count++;
	printf("%i", data->count);
	data->i++;
}

void	ft_putstr(char *str, t_data *data)
{
	while (str[data->i] && str)
		ft_putchar(str[data->i], data);
}

void	ft_putnbr(int nb, t_data *data)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', data);
		n = -n;
		data->count++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
	{
		ft_putchar(n + '0', data);
		data->count++;
	}
}
