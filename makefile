# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldes-cou <ldes-cou@student.fr>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/12 10:12:55 by ldes-cou          #+#    #+#              #
#    Updated: 2021/02/12 10:34:57 by ldes-cou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_init_struct.c \
annexe.c 
ft_tab(const char *str, va_list 
ft_convert_s(va_list ap, t_data *data) ft_init_type(t_data *data) //


OBJS	=	${SRCS:.c=.o}

CC	=	clang
RM	=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

$(NAME):	${OBJS}
	ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean:
	${RM} ${OBJS} 

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:all clean fclean re bonus
