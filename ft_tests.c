/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:51:20 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/11 23:45:25 by Sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdarg.h>
#include "ft_printf.h"

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
	char *str;
	int ret_moi;
	int ret_vrai;
	
	str = "you";
	ret_moi = ft_printf("Hello %s !\n", str);
    	ret_vrai= printf("Hello %s !\n", str);
    	printf("ma f°:%i\nla vraie f°:%i\n", ret_moi, ret_vrai);
	return (0);
}

