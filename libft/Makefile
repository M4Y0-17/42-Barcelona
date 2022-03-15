# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amayo-ca <amayo-ca@student.42barc...>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/18 18:07:38 by amayo-ca          #+#    #+#              #
#    Updated: 2022/02/10 11:10:01 by amayo-ca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_strlcat.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlcpy.c ft_strnstr.c
INCLUDE		= libft.h
OBJS		= ${SRCS:.c=.o}
NAME		= libft.a
CC			= gcc
RM			= rm -f
AR			= ar rc
RN			= ranlib
CFLAGS		= -Wall -Wextra -Werror
.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}
			${RN} ${NAME}

all:		${NAME}
clean:
			${RM} ${OBJS}
fclean:		clean
			${RM} ${NAME}
re:			fclean all
.PHONY:		all clean fclean re