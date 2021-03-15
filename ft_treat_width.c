/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:40:19 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 11:13:58 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_treat_width(t_data *d)
{
	int i;

	i = -1;
	if ((d->zero && !d->dot) && !d->minus)
	{
		if (d->sign == 1)
			ft_putchar('-', d);
		if ((d->type == 'i' || d->type == 'd') && d->zero && d->precision)
		{
			while (++i < d->len)
				ft_putchar(' ', d);
		}
		else
		{
			while (++i < d->len)
				ft_putchar('0', d);
		}
	}
	else
	{
		while (d->len--)
			ft_putchar(' ', d);
	}
}
