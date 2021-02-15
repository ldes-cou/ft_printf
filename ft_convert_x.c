/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:13:12 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/15 16:22:25 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libftprintf.h"

void	ft_convert_x_lo(va_list ap, t_data *data)
{
	ft_putnbr_base(va_arg(ap, int), HEXA_LO, data);

}
void	ft_convert_x_up(va_list ap, t_data *data)
{
	ft_putnbr_base(va_arg(ap, int), HEXA_UP, data);	
}

