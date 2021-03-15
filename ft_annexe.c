/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_annexe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:58:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 11:42:38 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->count++;
}

void	ft_putstr(char *str, t_data *data)
{
	write(1, str, ft_strlen(str));
	data->count = data->count + ft_strlen(str);
}

void	ft_putnbr(int nb, t_data *data)
{
	long int n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-', data);
		n = -n;
	}
	if (n > 9)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
		ft_putchar(n + '0', data);
}

void	ft_putnbr_u(int nb, t_data *data)
{
	long long int n;

	n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10, data);
		ft_putnbr(n % 10, data);
	}
	else
		ft_putchar(n + '0', data);
}

char	*ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			str[i] -= 32;
		i++;
	}
	return (str);
}
