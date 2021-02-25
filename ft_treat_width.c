/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 10:40:19 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/25 15:53:42 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_treat_width(t_data *data)
{
	int i;

	i = -1;
	if (data->minus)
	{
		while (data->len)
		{	
			ft_putchar(' ', data);
			data->len--;
		}
	}
	if (data->zero && !data->minus && (data->type != 'i' && data->dot))
	{
		if (data->sign == 1)
			ft_putchar('-', data);
		while (++i < data->len)
			ft_putchar('0', data);
	}
	else
	{
		while (data->len)
		{
			ft_putchar(' ', data);
			data->len--;
		}
	}	return ;
}
	
