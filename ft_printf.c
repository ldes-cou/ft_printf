/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:51:20 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/19 17:31:44 by Sophie           ###   ########.fr       */
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
	char *s;
	int ret_moi;
	int ret_vrai;
	
	s = "Hello!";
	ret_moi = ft_printf("%0-20s\n", s);
	ret_vrai= printf("%0-20s\n", s);
   	printf("ma f°:%i\nla vraie f°:%i\n", ret_moi, ret_vrai);
	return (0);
}

