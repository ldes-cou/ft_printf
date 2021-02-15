/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   annexe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 10:58:38 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/15 16:24:38 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
void	ft_putchar(char c, t_data *data)
{
	write(1, &c, 1);
	data->count++;
}

void	ft_putstr(char *str, t_data *data)
{
	while (*str)
	{
		ft_putchar(*str, data);
		str++;
	}
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

void		ft_putnbr_base(int nbr, char *base, t_data *data)
{
	long long int		dividende;
	size_t			size_base;

	dividende = nbr;
	size_base = ft_strlen(base);
	if (dividende < 0)
	{
		ft_putchar('-', data);
		dividende = -dividende;
	}
	if (dividende >= (long long int)size_base)
	{
		ft_putnbr_base(dividende / size_base, base, data);
		ft_putchar(base[dividende % size_base], data);
	}
	else
		ft_putchar(base[dividende % size_base], data);
}
