/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 14:27:41 by ldes-cou          #+#    #+#             */
/*   Updated: 2021/02/11 15:45:13 by ldes-cou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
//# include "libft/libft.h"

#define FLAGS "-0.*"
#define TYPE "cspdiuxX%"
#define HEXA_LO "0123456789abcdef"
#define	HEXA_UP	"0123456789ABCDEFG"

//definir les types dans la structure pour iterer dedans 
typedef void(*f)(void *, ...);

typedef struct s_data
{
	char	buf[2048];
	int		converter;
	int		width;
	int		precison;
	int		len;
	int		i;
	int		type;
	int		count;
	f		fun_array[9];
}				t_data;

void	ft_init_struct(t_data *data);//creer une fonction  reinitialisier la struct
void	ft_putnbr(int);
void	ft_putchar(char c, t_data *data);
void	ft_putstr(char *str, t_data *data);
void	ft_tab(const char *str, va_list *ap, t_data *data);
void	ft_convert_s(va_list ap, t_data *data);
void	ft_init_type(t_data *data);
#endif

