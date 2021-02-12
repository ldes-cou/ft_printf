/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldes-cou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 11:38:24 by Sophie            #+#    #+#             */
/*   Updated: 2021/02/12 11:55:59 by ldes-cou         ###   ########.fr       */
/*   Updated: 2021/02/10 10:27:03 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_init_struct(t_data *data)
{
	data->converter = 0;
	data->width = 0; 
	data->precison = 0;
	data->len = 0;
	data->i = 0;
	data->count = 0;
}
