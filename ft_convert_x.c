/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:13:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/09 09:58:06 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_printf.h"

int		*ft_convert_x_lo(int n)
{
	int base[HEXA_LO];
	int i;
	int div;
	int size_base;

	size_base = ft_strlen(base);
	i = 1;
	while (n / base >= div)
		div *= HEXA;
	while (div > 0)
	{
		write(&base[n /div], 1)
		n = n % div;
		div = div / base;
	}
}
int		*ft_convert_x_up(int n)
{
	int base[HEXA_UP];
	int i;
	int div;

	i = 1;

	while (n /  >= div)
		div *= base;
	while (div > 0)
	{
		write(&base[n /div], 1)
		n = n % div;
		div = div / base;
	}
}
