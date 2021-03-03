# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldes-cou <ldes-cou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/26 13:44:24 by ldes-cou          #+#    #+#              #
#    Updated: 2021/03/03 14:34:42 by ldes-cou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
LIBFT = libft/libft.a

NAME = libftprintf.a

SRCS = ft_convert_i.c ft_convert_u.c ft_printf.c ft_treat_str_prec.c \
ft_checkflags.c ft_convert_percent.c ft_convert_x.c ft_treat_width.c \
ft_annexe.c ft_convert_c.c ft_convert_s.c ft_fun_array.c ft_parser.c \
ft_treat_precision.c  

FOlDER_O = ft_convert_i.o ft_convert_u.o ft_printf.o ft_treat_str_prec.o \
ft_checkflags.o ft_convert_percent.o ft_convert_x.o ft_treat_width.o \
ft_annexe.o ft_convert_c.o ft_convert_s.o ft_fun_array.o ft_parser.o \
ft_treat_precision.o 

OBJS =	${SRCS:.c=.o}

CC = clang -c -g
RM =	rm -f

CFLAGS = -Wall -Wextra -Werror -I./libft

$(NAME):	${OBJS}
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(SRCS)
	ar rcs ${NAME} ${OBJS}

all:	${NAME}

clean: 
	$(MAKE) clean -C ./libft
	${RM} ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libft
	${RM} ${NAME}
re: fclean all

.PHONY:all clean fclean re

