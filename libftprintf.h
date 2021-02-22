#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

#define FLAGS "-0.*"
#define TYPE "cspdiuxX%"
#define HEXA_LO "0123456789abcdef"
#define	HEXA_UP	"0123456789ABCDEF"
#define BUFFER_SIZE 4096

//definir les types dans la structure pour iterer dedans 
typedef void(*f)(void *, ...);
char		buf[BUFFER_SIZE];
int		i_buf[BUFFER_SIZE];

typedef struct s_data
{
	char		*arg;
	int		i_arg;
	int		width;
	int		precision;
	int		minus;
	int		zero;
	int		len;
	int		i;
	char		type;
	int		count;
	f		fun_array[9];
}				t_data;

/*utils*/
void	ft_putnbr(int, t_data *data);
void	ft_putnbr_u(int, t_data *data);
void	ft_putchar(char c, t_data *data);
void	ft_putstr(char *str, t_data *data);
void	ft_putnbr_base(int nbr, char *base, t_data *data);
size_t	ft_intlen(int n);
char	ft_strchr_type(char *str, char c);
/*initialisation*/
void	ft_tab(const char *str, va_list *ap, t_data *data);
void	ft_init_struct(t_data *data);
void	ft_init_type(t_data *data);
void	ft_init_flags(const char *format, va_list ap, t_data *data);
int	ft_check_flags(t_data *data);
/*parser*/
int	ft_check_flags(t_data *data);
int	ft_is_type(char c);
int	ft_parse_type(const char *str, t_data *data);
/*handler*/
void	ft_treat_width(va_list ap, t_data *data);
/*conversions*/
void	ft_convert_s(va_list ap, t_data *data);
void	ft_convert_i(va_list ap, t_data *data);
void	ft_convert_c(va_list ap, t_data *data);
void	ft_convert_x_lo(va_list ap, t_data *data);
void	ft_convert_x_up(va_list ap, t_data *data);
void	ft_convert_u(va_list ap, t_data *data);
void	ft_convert_percent(char c, t_data *data);
/*display*/
void	ft_init_buf(t_data *data);
void	ft_fill_buf(char c, t_data *data);
void	ft_display_buf(t_data *data);

#endif

