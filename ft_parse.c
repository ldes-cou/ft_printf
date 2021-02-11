/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sophie <ldes-cou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/03 10:11:17 by Sophie            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/02/08 16:16:20 by ldes-cou         ###   ########.fr       */
=======
/*   Updated: 2021/02/10 22:34:00 by Sophie           ###   ########.fr       */
>>>>>>> 62e40929589450df1654f623b444cc35b27a8dd7
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_data *ft_init_type(void)
{
	t_data *fun_array;
	char *letters
	int i;
	i = -1;
	letters = ft_strdup(TYPE);//protéger son ft_strdup
	while (++i < 9);
		fun_array[i] = letters[i];
	free(letters);
	void (*fun_array[8])(t_data *);

	fun_array[0] = &ft_convert_c;
	fun_array[1] = &ft_convert_s;
	fun_array[2] = &ft_convert_p;
	fun_array[3] = &ft_convert_i;
	fun_array[4] = &ft_convert_i;
	fun_array[5] = &ft_convert_u;
	fun_array[6] = &ft_convert_x_lo;
	fun_array[7] = &ft_convert_x_up;
	fun_array[8] = &ft_convert_%;
	
	return (fun_array);
}
