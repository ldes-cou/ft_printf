/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_str_prec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 10:52:52 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/15 10:58:25 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_treat_str_prec(char *str, t_data *data)
{
	size_t strlen;

	strlen = (int)ft_strlen(str);
	if (data->dot && (data->precision < (int)strlen))
		strlen = data->precision;
	else
		strlen = ft_strlen(str);
	return (strlen);
}

void	ft_putnstr(char *str, size_t n, t_data *data)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		ft_putchar(str[i], data);
		i++;
	}
}
