/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:51:20 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/26 13:51:02 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_data data;

	ft_init_struct(&data);
	va_start(ap, format);
	ft_tab(format, &ap, &data);
	va_end(ap);
	return (data.count);
}

int main()
{
	//(void)argc;
	//(void)argv;
	int	i;
	int ret_moi;
	int ret_vrai;
	
	i = 597;		
	
	ret_moi = ft_printf("%.5iSTOP", i);
	printf("%c", '\n');
	ret_vrai= printf("%.5iSTOP", i);
	printf("%c", '\n');
   	printf("ma f°:%i\nla vraie f°:%i\n",ret_moi, ret_vrai);
	return (0);
}

