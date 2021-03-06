/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 13:51:20 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/03/06 15:06:55 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int ft_printf(const char *format, ...)
{
	va_list ap;
	t_data data;

	ft_init_struct(&data);
	data.i = 0;
	data.count = 0;
	va_start(ap, format);
	ft_tab(format, &ap, &data);
	va_end(ap);
	return (data.count);
}

/*int main()
{
	//(void)argc;
	//(void)argv;
	//int i;
	//char *d;
	//char *e;
	//char *f;

	int ret_moi;
	int ret_vrai;
	
	//i = 94827;
	//d = "world";
	//e = "you";
	//f = "lol";
	//d = 'b';

	
	ret_moi = ft_printf("%*s", -32, "abc"); 
	printf("%c", '\n');
	ret_vrai = printf("%*s", -32, "abc");
	printf("%c", '\n');
   	printf("ma f°:%i\nla vraie f°:%i\n",ret_moi, ret_vrai);
	return (0);
}*/
/*int main()
{
	//(void)argc;
	//(void)argv;
	char i;
	char d;
	char e;
	char f;

	int ret_moi;
	int ret_vrai;
	
	i = 'h';
	d = 'w';
	e = 'y';
	f = 'l';
	//d = 'b';

	
	ret_moi = ft_printf("%1c%2c%3c%4c", i, d, e, f); 
	printf("%c", '\n');
	ret_vrai= printf("%1c%2c%3c%4c", i, d, e, f);
	printf("%c", '\n');
   	printf("ma f°:%i\nla vraie f°:%i\n",ret_moi, ret_vrai);
	return (0);
}*/
