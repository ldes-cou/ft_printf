/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldes-cou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 09:44:56 by Sophie            #+#    #+#             */
/*   Updated: 2021/02/11 15:18:40 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->count++;;
}

void	ft_putstr(char *str, t_data *data)
{
	while (*str)
	{
		ft_putchar(*str, data);
		str++;
	}
}

/*void	ft_putnbr(int nb)
{
	long int n;
	t_data data;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
		data.count++;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		ft_putchar(n + '0');
		data.count++;
	}
}
*/
