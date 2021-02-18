/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldes-cou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:38:24 by Sophie            #+#    #+#             */
/*   Updated: 2021/02/18 09:46:10 by Sophie           ###   ########.fr       */
/*   Updated: 2021/02/10 10:27:03 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_init_struct(t_data *data)
{
	data->width = 0; 
	data->precision = 0;
	data->len = 0;
	data->i = 0;
	data->count = 0;
	data->minus = 0;
	data->zero = 0;
}
