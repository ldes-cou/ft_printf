/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:13:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/12 15:40:10 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		*ft_convert_x_lo(int n)
{
	int base[16];
	int i;
	int div;

	base = HEXA_LO;
	i = 1;
	while (n / base >= div)
		div *= 16;
	while (div > 0)
	{
		ft_putchar(&base[n /div]);
		n = n % div;
		div = div / base;
	}
}
int		*ft_convert_x_up(int n)
{
	char *base;;
	int i;
	int div;
	int size_base;
	
	base = HEXA_LO;
	i = 1;
	while (n / base >= div)
		div *= base;
	while (div > 0)
	{
		ft_putchar(&base[n /div], 1);
		n = n % div;
		div = div / base;
	}
}
int main()
{
	int	i;

	i = 25;
	ft_convert_x_up(i);
	return (0);
}

