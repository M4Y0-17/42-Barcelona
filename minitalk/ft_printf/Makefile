# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/15 12:26:28 by amayo-ca          #+#    #+#              #
#    Updated: 2022/05/17 13:39:20 by amayo-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= src/ft_printf.c src/ft_print_char.c src/ft_print_d.c src/ft_print_ptr.c src/ft_print_string.c src/ft_print_unsigned.c src/ft_put_hex.c
INCLUDE		= libft.h
OBJS		= ${SRCS:.c=.o}
NAME		= libftprintf.a
CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib
CFLAGS		= -Wall -Wextra -Werror
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
all:		${NAME}
${NAME}:	${OBJS} includes/ft_printf.h
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re
